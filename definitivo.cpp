#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <windows.h>
#include <map>
#include <sstream> 
using namespace std;

//diseño para titulos 
void titulo(string title){

	int i; 
	int val;

	val = title.length();
	val = val + 20;

	for (i=0; i<= val; i++){
	
	cout<< "*";
}

cout<<"\n \n";


	for (i=0; i<= val; i++){
		
		cout<<" ";
		if(i==5){
			cout<< title;
				
		}
			cout<<" ";
	}
	
	cout<<"\n";
	
	for (i=0; i<= val; i++){
		
		cout<<"*";
	
		
	}

cout << "\n \n \n";

}

//COLOR DE LAS PALABRAS

void SetRedColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void SetGreenColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void ResetColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}



///////////////////////////////////////////////////////////////////////////////////////////////////////

const char *nombre_archivo = "vocabulario.dat";
struct Vocabulario{
	
	char palabra[50];
	char traduccion[50];
	char funcionalidad[70];
	
};






void Leer();
void Traducir();
void Crear();
void Actualizar();
void Borrar();
void LeerVocabulario(map<string, string> &vocabulario);
void TraducirTexto(const map<string, string> &vocabulario);




main(){
map<string, string> vocabulario;
    
LeerVocabulario(vocabulario);

	
	
	int opcion;
	char respuesta;
	
	do{
		
	
	
		titulo("Bienvenido al traductor del grupo No.5");
		cout<<"------------------------------------------------------------"<<endl;
		cout<<"**********************Elija una opcion**********************"<<endl;
		cout<<endl;
		cout<<"1. Agregar una palabra al vocabulario"<<endl;
		cout<<"2. Borrar palabra del vocabulario"<<endl;
		cout<<"3. Actualizar palabra del vocabulario"<<endl;
		cout<<"4. Traducir "<<endl;
		cout<<"5. Ver vocabulario"<<endl;
		cout<<"6. Traducir fragmentos de C++"<<endl;
		cout<<"7. Salir"<<endl;
		
		cout<<"------------------------------------------------------------"<<endl;
		cin>>opcion;
		system("cls");
		
		
		
		//INICIO DEL PROGRAMA
		
	switch (opcion) {
		
	

	 
            case 1:
			   		Crear();
            break; 
            
        	
         
            
         
            case 2: 
               		Borrar();
            break; 
                
                
                
                       
            case 3: 
            		Actualizar();
            break;
                
                
                
             case 4: 
    				Traducir();
             break;
			
			
			
			case 5: 
            		Leer();
            break;
			 
			      
           case 6:  
		   			TraducirTexto(vocabulario);
           break;
            
            
            case 7:
                cout << "SALIENDO DEL MENU" << endl;
            return 0;
            
                
            default: //SI SE SELECCIONA CUALQUIER NUMERO NO VALIDA: MOSTRAR EL MENSAJE DE:
            cout << "OPCION NO VALIDA" << endl;
            
        }
	
			cout<<endl;
			
///////////////////////////////////////////////////////////////////////		

        cout << "Desea realizar otra operacion? (s/n): ";
		cin >> respuesta;
		cout << endl; 	
	system("cls");
}	while(respuesta!='n');
	
	system("pause");
	return 0;
}



//INICIO DE FUNCIONES

bool PalabraExiste(const char* palabra) {
    FILE* archivo = fopen(nombre_archivo, "rb");
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return false;
    }

    Vocabulario vocabulario;
    while (fread(&vocabulario, sizeof(Vocabulario), 1, archivo)) {
        if (strcmp(palabra, vocabulario.palabra) == 0) {
            fclose(archivo);
            return true;
        }
    }

    fclose(archivo);
    return false;
}






void Leer(){

	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if(!archivo){
		archivo = fopen(nombre_archivo, "w+b");
	}

 Vocabulario vocabulario;
    int id = 0;
    fread(&vocabulario, sizeof(Vocabulario), 1, archivo);

    cout << "*********************************************************************************************************" << endl;
cout << setw(2) << "ID |" << setw(25) << left << "Palabra" << "|" << setw(25) << left << "Traducción" << "|" << setw(40) << left << "Funcionalidad" << endl;
cout << "_________________________________________________________________________________________________________" << endl;

do {
    cout << setw(2) << id << " |" << setw(25) << left << vocabulario.palabra << "|" << setw(25) << left << vocabulario.traduccion << "|" << setw(40) << left << vocabulario.funcionalidad << endl;
    fread(&vocabulario, sizeof(Vocabulario), 1, archivo);
    id += 1;
} while (feof(archivo) == 0);

    cout << "*********************************************************************************************************" << endl;


	fclose(archivo);
}



void Traducir() {
	
		FILE* archivo = fopen(nombre_archivo,"a+b");
		char res;
do{
	char palabra[50];
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	


		    cout << "Ingrese la palabra a traducir: ";
		    cin.ignore();
		    cin.getline(palabra, 50);
		
		    FILE* archivo = fopen(nombre_archivo, "rb");
		    if (!archivo) {
		        cerr << "Error al abrir el archivo." << endl;
		        return;
		    }
		    
		    cout <<endl;
		    cout <<"________________________________________________________"<<endl;
			
		    Vocabulario vocabulario;
		    bool encontrada = false;
		
		    while (fread(&vocabulario, sizeof(Vocabulario), 1, archivo)) {
		        if (strcmp(palabra, vocabulario.palabra) == 0) {
		        	
		        	encontrada=true;
		        	
		            cout << "Palabra: " << vocabulario.palabra << endl;
		            cout << "Traduccion: " << vocabulario.traduccion << endl;
		            cout << "Funcionalidad: " << vocabulario.funcionalidad << endl;
		            
		            break;
		        }
		    }
		
		if (!encontrada) {
			
			
            
            SetRedColor();
            std::cout << "Palabra no encontrada en el vocabulario." << std::endl;
            ResetColor();
           
        }		    
		    
	   
		 fclose(archivo); 
		 
		
		cout<<endl; 
		cout<<"________________________________________________" <<endl;
		cout<<"Desea ingresar otra palabra(s/n): ";
		cin>>res;
		system("cls");
		
		
	}while(res!='n');
	
}




void Crear(){
	
	FILE* archivo = fopen(nombre_archivo,"a+b");
	
	char res;
	Vocabulario vocabulario;
	do{
		
		fflush(stdin);	
		cout<<"Ingrese la palabra a traducir: ";
		cin.getline(vocabulario.palabra,50);
		
		
		// Verificar si la palabra ya existe en el archivo
        if (PalabraExiste(vocabulario.palabra)) {
            SetRedColor();
            cout << "La palabra ya existe en el vocabulario." << endl;
            ResetColor();
        } else {
		cout<<"Ingrese la traduccion: ";
		cin.getline(vocabulario.traduccion,50);
		cout<<"Ingrese la funcionalidad: ";
		cin.getline(vocabulario.funcionalidad,70);

	
		
		fwrite(&vocabulario,sizeof(Vocabulario),1,archivo);
		SetGreenColor();
		cout<<endl;
		std::cout<<"******************************************"<<std::endl;
		std::cout << "Palabra agregada correctamente." << std::endl;
		std::cout<<"******************************************"<<std::endl;
		cout<<endl;
		ResetColor();

	}
		cout<<"Desea ingresar otra palabra(s/n): ";
		cin>>res;
		
 	system("cls");
		
	
	}while(res=='s' || res=='S');
	fclose(archivo);
	

}






void Actualizar(){
	
	
	char respuesta;

    do {
	
		Leer();	
		
		cout<<"**************************************"<<endl;
		cout<<endl;
		cout<<endl;
	
	
		FILE* archivo = fopen(nombre_archivo,"r +b");
	
	Vocabulario vocabulario;
	int id=0;
	cout<<"Ingrese el ID que desea modificar: ";
	cin>>id;
	fseek(archivo,id * sizeof(Vocabulario), SEEK_SET); 

		
		fflush(stdin);	
		cout<<"Ingrese la palabra: ";
		cin.getline(vocabulario.palabra,50);
		
		cout<<"Ingrese la nueva traduccion: ";
		cin.getline(vocabulario.traduccion,50);
		
		cout<<"Ingrese la nueva funcionalidad: ";
		cin.getline(vocabulario.funcionalidad,70);
		
	
	
		
		fwrite(&vocabulario,sizeof(Vocabulario),1,archivo);
		
	fclose(archivo);
	Leer();	
	
		SetGreenColor();
		cout<<endl;
		std::cout<<"******************************************"<<std::endl;
		std::cout << "Palabra actualizada correctamente." << std::endl;
		std::cout<<"******************************************"<<std::endl;
		cout<<endl;
		ResetColor();
		
	
	cout << "Desea actualizar otra palabra (s/n)?: ";
        cin >> respuesta;
        
         	system("cls");
        
        
    } while (respuesta == 's' || respuesta == 'S');
}












void Borrar(){
	
	
	char respuesta;

    do {
	
	 Leer(); 
	  
	cout<<"***************************************************"<<endl;
	const char *nombre_archivo_temp = "archivo_temp-dat";
	 FILE* archivo = fopen(nombre_archivo,"rb");
	 FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	 
	 Vocabulario vocabulario;
	 int id=0, id_n=0;
	 cout<<"Ingrese el ID a eliminar: ";
	 cin>>id;
	 
	 while(	fread(&vocabulario,sizeof(Vocabulario),1,archivo)){
	 	
	 	 if(id_n!=id){
	 	 	
	 	fwrite(&vocabulario,sizeof(Vocabulario),1,archivo_temp);

		  }
	 	 id_n++;
	 }
	 fclose(archivo);
	 fclose(archivo_temp);
	

	archivo_temp = fopen(nombre_archivo_temp,"rb");
	archivo = fopen(nombre_archivo,"wb");
	
	 while(	fread(&vocabulario,sizeof(Vocabulario),1,archivo_temp)){
	 	
	 		fwrite(&vocabulario,sizeof(Vocabulario),1,archivo);
	 		
		
	 }
	
	fclose(archivo);	 
	 fclose(archivo_temp);
	  
	Leer(); 
	cout<<endl;
		
		SetGreenColor();
		std::cout<<"******************************************"<<std::endl;
		std::cout << "Palabra eliminada correctamente." << std::endl;
		std::cout<<"******************************************"<<std::endl;
		cout<<endl;
		ResetColor();
	
	cout << "¿Desea eliminar otra palabra (s/n)?: ";
        cin >> respuesta;
        
        system("cls");
    } while (respuesta == 's' || respuesta == 'S');
	
}

















void LeerVocabulario(map<string, string> &vocabulario) {
    FILE* archivo = fopen(nombre_archivo, "rb");
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    Vocabulario palabraTraduccion;

    while (fread(&palabraTraduccion, sizeof(Vocabulario), 1, archivo)) {
        vocabulario[palabraTraduccion.palabra] = palabraTraduccion.traduccion;
    }

    fclose(archivo);
}

void TraducirTexto(const map<string, string> &vocabulario) {
    FILE* archivo = fopen(nombre_archivo,"rb");
    string linea;
    char res;

    do {
        cout << "Ingresa el fragmento de codigo a traducir, dejar un espacio entre la palabra que desea traducir y el resto del codigo (escribe 'fin' en una linea separada para finalizar):\n" << endl;

        string texto = "";
        while (true) {
            getline(cin, linea);

            if (linea == "fin") {
                break;
            }

            texto += linea + "\n";  // Agregará un salto de línea después de cada línea leída.
        }

        if (texto.empty()) {
            continue;  // Si el fragmento está vacío, pedirá otro.
        }

        istringstream iss(texto);
        
        cout << "_______________________________________"<< endl;
        cout << "La traduccion es:" << endl;

        while (getline(iss, linea)) {
            istringstream issLinea(linea);
            string palabra;

            while (issLinea >> palabra) {
                if (vocabulario.find(palabra) != vocabulario.end()) {
                    SetGreenColor();
                    cout << vocabulario.at(palabra) << " ";
                    ResetColor();
                } else {
                    cout << palabra << " ";
                }
            }
// Agregar un salto de línea después de cada línea traducida.
            cout << endl;
        }
        	cout << "_______________________________________"<< endl;


        cout << "Desea ingresar otro fragmento de codigo?? (s/n): ";
        cin >> res;
        cin.ignore();  
        system("cls");

    } while (res == 's' || res == 'S');
}




