#include "Map.hpp"

int main()
{
    Map<int, const char *> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
     for (auto[key, value, index] : m)
     {
         printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
     }
     m[20] = "result";
     for (auto[key, value, index] : m)
     {
         printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
     }
    
    /*
     Map<int, const char*> p;
     p[30] = "Poo";
     p[10] = "C++";
     bool includes = m.Includes(p);
     if(includes)
     {
         printf("M includes P\n");
     }
     else
     {
         printf("M does not include P\n");
     }
     */
    
    return 0;
}
