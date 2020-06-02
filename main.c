#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <windowsx.h>

///Botones
HWND ventana,boton,boton2,label,lx,ly,texto,leertxt;

///Etiquetas estáticas
HWND tipos_conversion,bin,binr,oct,octr,hex,hexr,grados,gradosr;
int tx,ty;

int Longitud_cadena(char cad[]){
    int i=0;
    for(i=0;cad[i]!='\0';i++){
    }
    return i;
}

char enteroACaracter(int numero){
    return numero + '0';
}

LRESULT CALLBACK winProc(HWND hwnd,UINT msj,WPARAM wParam,LPARAM lParam){
    switch(msj){
    case WM_MOUSEMOVE:
        tx = GET_X_LPARAM(lParam);
        ty = GET_Y_LPARAM(lParam);
        char bufferx[100];
        char buffery[100];
        itoa(tx,bufferx,10);
        itoa(ty,buffery,10);
        SetWindowText(lx,bufferx);
        SetWindowText(ly,buffery);
        break;
    case WM_COMMAND: ///Referente a cuando se hace click

        if((HWND)lParam == boton){
            MessageBox(hwnd,"Le diste click al boton","Aviso",MB_OK | MB_ICONASTERISK);
        }


        if((HWND)lParam == label){
            MessageBox(hwnd,"Le diste click al texto","Aviso",MB_OK | MB_ICONASTERISK);
        }

        if((HWND)lParam == leertxt){
            char gtext[100],c[2];
            GetWindowText(texto,gtext,100);

            if(Longitud_cadena(gtext)<10)
            c[0]=enteroACaracter(Longitud_cadena(gtext));
            else{
                c[0]=enteroACaracter(Longitud_cadena(gtext)/10);
                c[1]=enteroACaracter(Longitud_cadena(gtext)%10);
            }
            MessageBox(hwnd,c,"Longitud de texto",MB_OK | MB_ICONINFORMATION);

            strupr(gtext);
            MessageBox(hwnd,gtext,"Mayusculas",MB_OK | MB_ICONASTERISK);
            strlwr(gtext);
            MessageBox(hwnd,gtext,"Minusculas",MB_OK | MB_ICONASTERISK);
            break;
        }

        break;

    case WM_DESTROY :
        PostQuitMessage(0);
        break;
    }
    DefWindowProc(hwnd,msj,wParam,lParam);
}

char app[] = "Mi clase";
int WINAPI WinMain(HINSTANCE ins,HINSTANCE ins2,LPSTR cmd, int estado){
    ///Ventana madre------"Contenido de la ventana","Título","Comportamiento y apariencia con botones y/o íconos"

    WNDCLASSEX vtn;
    vtn.cbClsExtra=0;
    vtn.cbSize=sizeof(WNDCLASSEX);
    vtn.cbWndExtra = 0;
    vtn.hbrBackground = (HBRUSH) (COLOR_HIGHLIGHT+1);
    vtn.hCursor = LoadCursor(NULL,IDC_ARROW);
    vtn.hIcon = NULL;
    vtn.hIconSm = NULL;
    vtn.hInstance = ins;
    vtn.lpfnWndProc = winProc;
    vtn.lpszClassName = app;
    vtn.lpszMenuName = NULL;
    vtn.style = CS_HREDRAW | CS_VREDRAW;

    if(!RegisterClassEx(&vtn)){
        MessageBox(HWND_DESKTOP,"Error al crear la clase","Error",MB_ICONERROR|MB_OK);
    }

///int x(posición horizontal),int y(posición vertical),nWidth (anchura),int nHeight(altura).

    ventana = CreateWindow(app,"Mi ventana",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,616.5,361.5,HWND_DESKTOP,NULL,ins,NULL);
    texto = CreateWindow("EDIT","",WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER,6,12,580,84,ventana,NULL,ins,NULL);

    ///Creación de etiquetas
    tipos_conversion = CreateWindow("STATIC","Tipos de conversion",WS_CHILD | WS_VISIBLE | SS_LEFT ,6,102,120,30,ventana,NULL,ins,NULL);
    bin = CreateWindow("STATIC","Bin:",WS_CHILD | WS_VISIBLE | SS_NOTIFY | SS_LEFT,6,156,14.25,9.75,ventana,NULL,ins,NULL);
    /*boton = CreateWindow("BUTTON","Boton",WS_CHILD | WS_VISIBLE,10,10,80,30,ventana,NULL,ins,NULL);
    boton2 = CreateWindow("BUTTON","Boton2",WS_CHILD | WS_VISIBLE,10,80,80,30,ventana,NULL,ins,NULL);
    label = CreateWindow("STATIC","Hola mundo, soy un label",WS_CHILD | WS_VISIBLE | SS_NOTIFY | SS_CENTER,100,50,150,40,ventana,NULL,ins,NULL);
    lx = CreateWindow("STATIC","0",WS_CHILD | WS_VISIBLE | SS_NOTIFY | SS_CENTER,10,300,80,20,ventana,NULL,ins,NULL);
    ly = CreateWindow("STATIC","0",WS_CHILD | WS_VISIBLE | SS_NOTIFY | SS_CENTER,90,300,80,20,ventana,NULL,ins,NULL);*/
        //leertxt = CreateWindow("BUTTON","Leer texto",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON|BS_CENTER,10,130,80,30,ventana,NULL,ins,NULL);

    if(!ventana){
        MessageBox(HWND_DESKTOP,"Error al crear la ventana","Error",MB_ICONERROR|MB_OK);

    }

    ShowWindow(ventana,SW_SHOWNORMAL);
    MSG msj;

    while(GetMessage(&msj,NULL,0,0)){
        DispatchMessage(&msj);
        TranslateMessage(&msj);

    }

    return (int) msj.wParam;

}
