#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef pair<string, int> pd;
struct myComp {
    constexpr bool operator()(
        pair<string, int> const& a,
        pair<string, int> const& b)
        const noexcept
    {
        if(a.second != b.second)
            return a.second < b.second;
        else
            return a.first > b.first;
    }
};
void showpq(priority_queue<pd, vector<pd>, myComp> g)
{
    while (!g.empty()) {
        cout << g.top().first
             << " => " << g.top().second
             << endl;
        g.pop();
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    string filename("input.strings");
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cout << "Could not open the file - '"<< filename << "'" << endl;
        return EXIT_FAILURE;
    }
    getline(input_file, line);
    input_file.close();
    
    struct tokens: std::ctype<char>
    {
        tokens(): std::ctype<char>(get_table()) {}
     
        static std::ctype_base::mask const* get_table()
        {
            typedef std::ctype<char> cctype;
            static const cctype::mask *const_rc= cctype::classic_table();
     
            static cctype::mask rc[cctype::table_size];
            std::memcpy(rc, const_rc, cctype::table_size * sizeof(cctype::mask));
            
            rc['!'] = std::ctype_base::space;
            rc['.'] = std::ctype_base::space;
            rc[','] = std::ctype_base::space;
            rc[' '] = std::ctype_base::space;
            return &rc[0];
        }
    };
    std::stringstream ss(line);
    ss.imbue(std::locale(std::locale(), new tokens()));
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings(begin, end);
    
    map<string, int> frecv_map;
    for (int i = 0; i < vstrings.size(); i++)
    {
        string key = vstrings[i];
        std::for_each(key.begin(), key.end(), [](char & c){
            c = ::tolower(c);
        });
        if(frecv_map.count(key) == 0)
            frecv_map[key] = 1;
        else
            frecv_map[key]++;
    }
    
    priority_queue<pd, vector<pd>, myComp> p_queue;
    for (auto const& x : frecv_map)
    {
        p_queue.push(make_pair(x.first, x.second));
    }
    showpq(p_queue);
    
    
    return 0;
}
