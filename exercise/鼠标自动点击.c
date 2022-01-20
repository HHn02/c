#include<stdio.h>
#include<windows.h>
int main()
{
  
        while (1)
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
            Sleep(5);
            if (GetAsyncKeyState(VK_ESCAPE))  
            {
                printf("\noff"); 
                break;
                    
            }
                 
        }

  
        
    return 0;
}
