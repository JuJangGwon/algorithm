// #include <iostream>

// using namespace std;

// int M_heap[100001];
// int pivot = 1;

// void pop()
// {
//     if (pivot == 1)
//     {
//         cout << "0" << "\n";
//         return ;
//     }
//     cout << M_heap[1] << "\n";
//     pivot--;
//     if (pivot == 1)
//         return ;
//     int parent = 1;
//     int child = 2;
//     M_heap[1] = M_heap[pivot];
//     while (child <= pivot)
//     {
//         if (M_heap[parent] < M_heap[child] && M_heap[child] < M_heap[child + 1])
//             child++;
//         if (M_heap[child] < M_heap[parent])
//             break;
//         int temp = M_heap[parent];
//         M_heap[parent] = M_heap[child];
//         M_heap[child] = temp;
//         parent = child;
//         child *= 2;
//     }
// }
// void push(int num)
// {
//     int c;

//     M_heap[pivot++] = num;
//     c = pivot - 1;
//     while (c != 1)
//     {
//         if(M_heap[c] > M_heap[c/2])
//         {
//             int temp = M_heap[c];
//             M_heap[c] = M_heap[c/2];
//             M_heap[c/2] = temp;
//             c /= 2;
//         }
//         else
//             break;
//     }
//     for (int i = 0; i < pivot; i++)
//     {
//         cout << M_heap[i] << ", ";
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    
//     int a;
//     cin >> a;

//     for (int i = 0; i < a; i++)
//     {
//         int b;
//         cin >> b;
//         if (b == 0)
//             pop();
//         else
//             push(b);
//     }
//     return 0;
// }

#include <iostream>
#include <queue>

using namespace std;

int main()
{
   ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
    priority_queue<int> pq;
    int a;

    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int v;
        cin >> v;
        if(v == 0)
        {
            if (pq.empty() == true)
                cout << "0" << "\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
            pq.push(v);
    }
    return 0;
}