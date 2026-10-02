/* LEETCODE QUESTION - Valid anagram
Time Limit Exceeded
35 / 56 testcases passed 
Time complexity close to O(n3) or more!!
*/
#include <string.h> // strlen
#include <stdbool.h> // bool
#include <stdio.h> // printf

bool is_it_saved(int index, int *arr, int arr_len)
{
    int i = 0;
    while (i < arr_len)
    {
        if (index == arr[i])
        {
            //printf("index:%d - arr[i]%d\n", index, arr[i]);
            return (true);
        }
        i++;
    }
    //printf("j [%d] not saved\n", index);
    return (false);
    
}
// save_index(j, saved_index, saved_len)
void save_index(int index, int *arr, int arr_len)
{
    int i = 0;
    while (i < arr_len)
    {
        if (arr[i] == -1)
        {
            arr[i] = index;
            //printf("adding j [%d]?\n", index);
            return;
        }
        i++;
    }
}
bool is_there_null_in_saved_index(int *saved, int len)
{
    int i = 0;
    while (i < len)
        {
            if (saved[i] == -1)
                return (true);
            i++;
        }
    return (false);
}

bool isAnagram(char* s, char* t)
{
    // first check
    int saved_len = strlen(s);

    if (saved_len != strlen(t))
        return (false);
    // Init the saved index int array
    //int a[10] = {0, 1, 2};
    int saved_index[saved_len]; // = malloc(sizeof(int) * saved_len);
    for(int z = 0; z < saved_len; z++)
        saved_index[z] = -1;        
    
    int i = 0;
    // looping over the first string --> ANAGRAM
    while (s[i] != '\0')
    {
        int j = 0;
        // looping over the second string --> NAGARAM
        while (t[j] != '\0')
        {
            // if index j is in the saved index, just skip it
            //j = 0;
            //if (is_it_saved(j, saved_index, saved_len));
            {
                //printf("index j[%d] was saved, so I can increment it\n", j);
                //j++;
            }
            // if the char is the same, save the index, and break of the loop
            if (s[i] == t[j] && t[j] && !(is_it_saved(j, saved_index, saved_len)))
            {
                //printf("s[i] -> %c[%d]\n", s[i], i);
                //printf("t[j] -> %c[%d]\n", t[j], j);

                save_index(j, saved_index, saved_len);
                break;
            }

        j++;
        }
    i++;
    }
    // what to do at the end of the loop
    return(!(is_there_null_in_saved_index(saved_index, saved_len)));
}
