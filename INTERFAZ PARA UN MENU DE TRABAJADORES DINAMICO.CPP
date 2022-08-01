/*DISEÑAR UN PROGRAMA QUE A TRAVES DE UN MENU DE OPCIONES REALICE LO SIGUENTE:
-INSERTAR DATOS-, -REPORTES- (EN GENERAL, POR CATEGORIA), ELIMINAR DATO,-MODIFICAR
 DATO-, -CONSULTAR DATOS-, ORDENAR DATOS Y SALIR. EL PROGRAMA TRATARA DEL INGRESO DE LOS
 TRABAJADORES DE UNA EMPRESA CON LOS SIGUIENTES DATOS: CODIGO DEL TRABAJADOR,
 APELLIDOS Y NOMBRES, CATEGORIA (AUXILIAR, TECNICO O PROFESIONAL), SEXO, ESTADO
 CIVIL (SOLTERO O CASADO), PROFESION U OCUPACION, CARGO (OBRERO,ADMINISTRATIVO
 ,JEFE O DIRECTOR), SUELDO BASICO, BONIFICACION, DESCUENTO, BONIFICACION POR
 RIESGO DE VIDA(SOLO PARA OBREROS), BONIFICACION POR CAPACITACION (SOLO PARA
 TECNICOS), RETENCION DE IMPUESTOS (SOLO PARA PROFESIONALES). APLICAR
 FUNCIONES CON PASO DE PARAMETROS. TRABAJAR REGISTRO Y ARCHIVOS.*/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#define fin_lista 0
struct datos
{
	char cod[10];
	char apynom[20];
	char cat;//AUXILIAR, TECNICO O PROFESIONAL
	char sexo;//Masculino, Femenino
	char ec;// SOLTERO O CASADO
   char prof[15]; // profesion u ocupacion
	char cargo;// OBRERO(O),ADMINISTRATIVO(A),JEFE(J) O DIRECTOR(D)
	float sbasico;
	float boni;
	float desc;
	float bonxrv;//solo obreros
	float bonxcap;//SOLO PARA TECNICOS
	float ri;//solo para profecionales
   float tot;
}dat;
typedef struct dinamica
{
	char cod[10];
	char apynom[20];
	char cat;
	char sexo;
	char ec;
   char prof[15];
	char cargo;
	float sbasico;
	float boni;
	float desc;
	float bonxrv;
	float bonxcap;
	float ri;
   float tot;
   struct dinamica *sig;
}din;
#define tam sizeof(din)
void Insertar(struct datos xdat[],int *xi);//,struct datos xaux[],struct datos xtec[],struct datos xpro[],int *xa,int *xt,int *xp);
void Mostrar(struct datos xdat[],int xi);//,struct datos xaux[],struct datos xtec[],struct datos xpro[],int xa,int xt,int xp);
void Eliminar(struct datos xdat[],int *xi);//,struct datos xaux[],struct datos xtec[],struct datos xpro[],int *xa,int *xt,int *xp);
void Modificar(struct datos xdat[],int xi);//,struct datos xaux[],struct datos xtec[],struct datos xpro[],int *xa,int *xt,int *xp);
void Ordenar(struct datos xdat[],int xi);
void Consultar(struct datos xdat[],int xi);
void InsertarD(); 
void MostrarD();
void EliminarD();
void ModificarD();
void OrdenarD();
void ConsultarD();
FILE*p;
din *comienzo, *nuevo, *aux, *temp;
char nom[15];
void main()
{
   system("color F9");
	int i=0;
   comienzo=fin_lista;
   setlocale(LC_ALL,"spanish");
  	struct datos dat[100];
  	cout<<"Ingrese nombre del archivo ";
  	cin>>nom;
  	int opc,elec;
   do
	{
		clrscr();
      system("color F9");
		gotoxy(42,8);cout<<"        TIPO DE ESTRUCTURA"<<endl;
		gotoxy(42,9);cout<<"   ---------------------------"<<endl;
		gotoxy(42,10);cout<<"|--\t1.- DINAMICA\t--|"<<endl;
		gotoxy(42,11);cout<<"|--\t2.- ESTATICA\t--|"<<endl;
		gotoxy(42,12);cout<<"|--\t3.- SALIR \t--|"<<endl;
		gotoxy(42,13);cout<<"   ---------------------------\n"<<endl;
		gotoxy(40,14);cout<<" Ingrese el numero de su opcion ==> ";
		cin>>elec;
	}
	while(elec>3);
   if(elec==1)
   {
   	do
		{
			clrscr();
      	system("color F9");
			gotoxy(42,8);cout<<"\t\tMENU"<<endl;
			gotoxy(42,9);cout<<"   ---------------------------"<<endl;
			gotoxy(42,10);cout<<"|--\t1.- Insertar Datos\t--|"<<endl;
			gotoxy(42,11);cout<<"|--\t2.- Mostrar Reportes\t--|"<<endl;
			gotoxy(42,12);cout<<"|--\t3.- Eliminar Datos\t--|"<<endl;
			gotoxy(42,13);cout<<"|--\t4.- Modificar Datos\t--|"<<endl;
			gotoxy(42,14);cout<<"|--\t5.- Ordenar Datos\t--|"<<endl;
			gotoxy(42,15);cout<<"|--\t6.- Consultar Datos\t--|"<<endl;
			gotoxy(42,16);cout<<"|--\t7.- Salir             \t--|"<<endl;
			gotoxy(42,17);cout<<"   ---------------------------\n"<<endl;
			gotoxy(40,18);cout<<" Ingrese el numero de su opcion==> ";
			cin>>opc;
			switch(opc)
			{
      		case 1: InsertarD();break;
				case 2: MostrarD();break;
				case 3: EliminarD();break;
		  		case 4: ModificarD();break;
		  		case 5: OrdenarD();break;
		  		case 6: ConsultarD();break;
			}
		}while(opc<7);
   }
   if(elec==2)
   {
		do
		{
			clrscr();
      	system("color F9");
			gotoxy(42,8);cout<<"\t\tMENU"<<endl;
			gotoxy(42,9);cout<<"   ---------------------------"<<endl;
			gotoxy(42,10);cout<<"|--\t1.- Insertar Datos\t--|"<<endl;
			gotoxy(42,11);cout<<"|--\t2.- Mostrar Reportes\t--|"<<endl;
			gotoxy(42,12);cout<<"|--\t3.- Eliminar Datos\t--|"<<endl;
			gotoxy(42,13);cout<<"|--\t4.- Modificar Datos\t--|"<<endl;
			gotoxy(42,14);cout<<"|--\t5.- Ordenar Datos\t--|"<<endl;
			gotoxy(42,15);cout<<"|--\t6.- Consultar Datos\t--|"<<endl;
			gotoxy(42,16);cout<<"|--\t7.- Salir             \t--|"<<endl;
			gotoxy(42,17);cout<<"   ---------------------------\n"<<endl;
			gotoxy(40,18);cout<<" Ingrese el numero de su opcion==> ";
			cin>>opc;
			switch(opc)
			{          
      		case 1: Insertar(dat,&i);break;
				case 2: Mostrar(dat,i);break;
				case 3: Eliminar(dat,&i);break;
		  		case 4: Modificar(dat,i);break;
		  		case 5: Ordenar(dat,i);break;
		  		case 6: Consultar(dat,i);break;
			}
		}while(opc<7);
   }
   clrscr();
   cout<<endl;
	gotoxy(42,8);cout<<"\t              (....MUCHAS GRACIAS...) "<<endl;
	gotoxy(42,9);cout<<"\t                    `--, ,-----´ "<<endl;
	gotoxy(42,10);cout<<"\t       @@@            /  /"    <<endl;
	gotoxy(42,11);cout<<"\t     @     @         ,       "<<endl;
	gotoxy(42,12);cout<<"\t     @     @       o00o   "<<endl;
	gotoxy(42,13);cout<<"\t       @@@        oo@@"<<endl;
	gotoxy(42,14);cout<<"\t        @           @"<<endl;
	gotoxy(42,15);cout<<"\t       @@@         @"<<endl;
	gotoxy(42,16);cout<<"\t      @ @  @     @"<<endl;
	gotoxy(42,17);cout<<"\t     @  @    @@"<<endl;
	gotoxy(42,18);cout<<"\t    @   @                        "<<endl;
	gotoxy(42,19);cout<<"\t   @    @"<<endl;
	gotoxy(42,20);cout<<"\t  @     @                        "<<endl;
	gotoxy(42,21);cout<<"\t        @                       "<<endl;
	gotoxy(42,22);cout<<"\t        @@                       "<<endl;
	gotoxy(42,23);cout<<"\t       @  @                      "<<endl;
	gotoxy(42,24);cout<<"\t      @    @                     "<<endl;
	gotoxy(42,25);cout<<"\t     @      @                    "<<endl;
	gotoxy(42,26);cout<<"\t    @        @                   "<<endl;
	gotoxy(42,27);cout<<"\t   @          @                  "<<endl;
	gotoxy(42,28);cout<<"\t @@          @@               "<<endl;
   system("color F2");
   cout<<endl;
   system("pause");
	//getch();
}
void Insertar(struct datos xdat[],int *xi)//,struct datos xaux[],struct datos xtec[],struct datos xpro[],int *xa,int *xt,int *xp)
{
	p=fopen(nom,"w");
	int q,opcion;
	q=*xi;
   do
	{
		clrscr();
      system("color F9");
		gotoxy(42,8);cout<<"               SUBMENU"<<endl;
		gotoxy(45,9);cout<<"   ---------------------------"<<endl;
		gotoxy(45,10);cout<<"|--\t1.- Auxiliar\t\t--|"<<endl;
		gotoxy(45,11);cout<<"|--\t2.- Tecnico\t\t--|"<<endl;
		gotoxy(45,12);cout<<"|--\t3.- Profesional\t\t--|"<<endl;
		gotoxy(45,13);cout<<"|--\t4.- Volver\t\t--|"<<endl;
		gotoxy(45,14);cout<<"   ---------------------------\n"<<endl;
		gotoxy(42,15);cout<<" Ingrese el numero de su opcion ==> ";
		cin>>opcion;
      if(opcion>=4){break;}
   	gotoxy(28,17);cout<<"============= Recolectando los datos del Trabajador <"<<(*xi+1)<<">=============="<<endl;
   	gotoxy(28,18);cout<<"Ingrese el codigo del Trabajador: ";
   	cin>>xdat[q].cod;
   	gotoxy(28,19);cout<<"Ingrese el apellido y nombre del trabajador: ";
   	gets(xdat[q].apynom);
   	gotoxy(28,20);cout<<"Ingrese el sexo del trabajador ((F)FEMENINO - (M)MASCULINO): ";
   	cin>>xdat[q].sexo;
   	gotoxy(28,21);cout<<"Ingrese el estado civil del trabajador ((S)SOLTERO/A - (C)CASADO/A): ";
   	cin>>xdat[q].ec;
   	gotoxy(28,22);cout<<"Ingrese la profesion/ocupacion del trabajador: ";
   	gets(xdat[q].prof);
   	gotoxy(28,23);cout<<"Ingrese el cargo del trabajador ((O)OBRERO - (A)ADMINISTRATIVO - (J)JEFE - (D)DIRECTOR): ";
   	cin>>xdat[q].cargo;
   	gotoxy(28,24);cout<<"Ingrese el sueldo basico del trabajador: ";
   	cin>>xdat[q].sbasico;
   	gotoxy(28,25);cout<<"Ingrese la bonificacion del trabajador: ";
   	cin>>xdat[q].boni;
   	gotoxy(28,26);cout<<"Ingrese el descuento del trabajador: ";
   	cin>>xdat[q].desc;
   	xdat[q].tot=xdat[q].sbasico+xdat[q].boni-xdat[q].desc;
   	if(xdat[q].cargo=='O')
   	{
   		gotoxy(28,27);cout<<"Ingrese la bonificacion por riesgo de vida del obrero ";
      	cin>>xdat[q].bonxrv;
      	xdat[q].tot+=xdat[q].bonxrv;
   	}else{xdat[q].bonxrv=0;}
   	if(opcion==2)
   	{
   		gotoxy(28,28);cout<<"Ingrese la bonificacion por capacitacion del tecnico ";
      	cin>>xdat[q].bonxcap;
      	xdat[q].tot+=xdat[q].bonxcap;
   	}else{xdat[q].bonxcap=0;}
   	if(opcion==3)
   	{
   		gotoxy(28,29);cout<<"Ingrese la retencion de impuesto del profesional ";
   		cin>>xdat[q].ri;
      	xdat[q].tot-=xdat[q].ri;
   	}else{xdat[q].ri=0;}
   	if(opcion==1)
   	{
      	xdat[q].cat='A';
   	}
   	if(opcion==2)
   	{
      	xdat[q].cat='T';
   	}
   	if(opcion==3)
   	{
     		xdat[q].cat='P';
   	}
      (*xi)++;
      q++;
   	fwrite(&xdat,sizeof(xdat),1,p);
   }
	while(opcion<4);
   fclose(p);

}
void Mostrar(struct datos xdat[],int xi)
{
	if(xi==0)//si no hay datos
   {
   	gotoxy(40,20);cout<<"No hay datos en el registro. No hay nada que mostrar"<<endl;
   	getch();
   }else
   {
   	clrscr();
   	system("color F9");
   	int j;
      cout<<"\n\n                                                       REPORTE DEL TRABAJADOR "<<endl;
      cout<<"--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
      cout<<" COD | NOMBRES Y APELLIDOS | CATEG | SEXO | E.CIVIL | PROF./OCUP. | CARGO | S.BASICO | BONIF. | DESC.| B.RIESGO | B.CAP. | R.IMP. | S.TOTAL"<<endl;
      cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
      int h=0;
      for(j=0;j<xi;j++)
      {
      	if(xdat[j].cat=='A')
      	{
         	p=fopen(nom,"r");
            cout<<(h+1)<<") ";
            printf("%5s %10s %10c %10c %11c %14s %13c %10.1f %10.1f %10.1f %10.1f %11.1f %14.1f %13.1f \n", xdat[j].cod,xdat[j].apynom,xdat[j].cat,xdat[j].sexo,xdat[j].ec,xdat[j].prof,xdat[j].cargo,xdat[j].sbasico,xdat[j].boni,xdat[j].desc,xdat[j].bonxrv,xdat[j].bonxcap,xdat[j].ri,xdat[j].tot);
            fclose(p);
            h++;
         }
      }
      if(xdat[j].cat!='A')
      {
      	cout<<"No hay auxiliares en el registro. No hay nada que mostrar"<<endl;
      }
      cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
      h=0;
      for(j=0;j<xi;j++)
      {
      	if(xdat[j].cat=='T')
         {
         	p=fopen(nom,"r");
            cout<<(h+1)<<") ";
            printf("%5s %10s %10c %10c %11c %14s %13c %10.1f %10.1f %10.1f %10.1f %11.1f %14.1f %13.1f \n", xdat[j].cod,xdat[j].apynom,xdat[j].cat,xdat[j].sexo,xdat[j].ec,xdat[j].prof,xdat[j].cargo,xdat[j].sbasico,xdat[j].boni,xdat[j].desc,xdat[j].bonxrv,xdat[j].bonxcap,xdat[j].ri,xdat[j].tot);
            fclose(p);
            h++;
         }
      }
      if(xdat[j].cat!='T')
      {
      	cout<<"No hay tecnicos en el registro. No hay nada que mostrar"<<endl;
      }
      cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
      h=0;
      for(j=0;j<xi;j++)
      {
      	if(xdat[j].cat=='P')
         {
         	p=fopen(nom,"r");
            cout<<(h+1)<<") ";
            printf("%5s %10s %10c %10c %11c %14s %13c %10.1f %10.1f %10.1f %10.1f %11.1f %14.1f %13.1f \n", xdat[j].cod,xdat[j].apynom,xdat[j].cat,xdat[j].sexo,xdat[j].ec,xdat[j].prof,xdat[j].cargo,xdat[j].sbasico,xdat[j].boni,xdat[j].desc,xdat[j].bonxrv,xdat[j].bonxcap,xdat[j].ri,xdat[j].tot);
            fclose(p);
            h++;
         }
      }
      if(xdat[j].cat!='P')
      {
      	cout<<"No hay profesionales en el registro. No hay nada que mostrar"<<endl;
      }
      cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   	getch();
   }
}
void Eliminar(struct datos xdat[],int *xi)//,struct datos xaux[],struct datos xtec[],struct datos xpro[],int *xa,int *xt,int *xp)
{
	int opcion;
   int tot=*xi;
   int cont=0,con=0;
   if(tot==0)//si no hay datos
   {
   	gotoxy(40,20);cout<<"No hay datos en el registro. No se puede eliminar"<<endl;
   	getch();
   }else
   {
		do
		{
			clrscr();
      	system("color F9");
			gotoxy(42,8);cout<<"               SUBMENU"<<endl;
			gotoxy(42,9);cout<<"   ---------------------------"<<endl;
			gotoxy(42,10);cout<<"|--\t1.- Codigo\t\t--|"<<endl;
			gotoxy(42,11);cout<<"|--\t2.- Nombre\t\t--|"<<endl;
			gotoxy(42,12);cout<<"|--\t3.- Volver\t\t--|"<<endl;
			gotoxy(42,13);cout<<"   ---------------------------"<<endl;
			gotoxy(42,14);cout<<" Ingrese el numero de su opcion ==> ";
			cin>>opcion;
      	if(opcion>2)
      	{
      		break;
      	}
      	if(opcion==1 && (*xi)!=0)
      	{
      		p=fopen(nom,"r");
      		char xcod[10];
            gotoxy(48,16);cout<<"===== CODIGOS ===== ";
            gotoxy(42,17);
            for(int j=0;j<*xi;j++)
            {
            	cout<<xdat[j].cod;
               if((j+1)!=*xi){
               cout<<"  ||  ";}
            }
      		gotoxy(42,18);cout<<"Ingrese el codigo del trabajador: ";
         	gets(xcod);
         	int inf=0,sup=(*xi),mitad,n=0;
  				char band='F';
   			while((inf<=sup)&& n<*xi)
   			{
   				mitad=(inf+sup)/2;
      			if(strcmp(xdat[mitad].cod,xcod)==0)
      			{
      				band='V';
         			break;
      			}
      			if(strcmp(xdat[mitad].cod,xcod)>0)
      			{                            // 0 1 2 3 4
      				sup=mitad;               //  2 3 4 5 6
         			mitad=(inf+sup)/2;
      			}
      			if(strcmp(xdat[mitad].cod,xcod)<0)
      			{
      				inf=mitad;
         			mitad=(inf+sup)/2;
      			}
      			n++;
         	}
   			if(band=='V')
   			{
            	for(int t=(mitad);t<(*xi);t++)
      			{
      				xdat[t]=xdat[t+1];
      			}
         		(*xi)--;
            	gotoxy(42,19);cout<<"El registro de codigo "<<xcod<<" ha sido eliminado";
            	fwrite(&xdat,sizeof(xdat),1,p);
            	getch();
   			}
   			else
   			{
   				gotoxy(42,20);cout<<"El codigo "<<xcod<<" NO se encuentra en el registro";
               getch();
   			}
            cont++;
         	fclose(p);
      	}
         if(cont==0 && opcion==1)
         {
            gotoxy(42,16);cout<<"No hay datos en el registro. No se puede eliminar"<<endl;
            getch();
         }
      	//NOMBRE
      	if(opcion==2 && (*xi)!=0)
      	{
      		p=fopen(nom,"r");
      		char xnom[20];
            gotoxy(48,16);cout<<" ===== NOMBRE/APELLIDO ===== ";
            gotoxy(42,17);
            for(int j=0;j<*xi;j++)
            {
            	cout<<xdat[j].apynom;
               if((j+1)!=*xi){
               cout<<"  ||  ";}
            }
      		gotoxy(42,18);cout<<"Ingrese el nombre del trabajador: ";
         	cin>>xnom;
         	int inf=0,sup=(*xi),mitad,n=0;
         	char band='F';
         	while((inf<=sup)&& n<(*xi))
         	{
         		mitad=(inf+sup)/2;
            	if(strcmp(xdat[mitad].apynom,xnom)==0)
            	{
            		band='V';
            		break;
            	}
            	if(strcmp(xdat[mitad].apynom,xnom)>0)
            	{
            		sup=mitad;
               	mitad=(inf+sup)/2;
      			}
      			if(strcmp(xdat[mitad].apynom,xnom)<0)
      			{
      				inf=mitad;
         			mitad=(inf+sup)/2;
      			}
      			n++;
         	}
   			if(band=='V')
   			{
            	for(int t=(mitad);t<(*xi);t++)
      			{
      				xdat[t]=xdat[t+1];
      			}
         		(*xi)--;
              gotoxy(42,19);cout<<"El registro de nombre y apellido "<<xnom<<" ha sido eliminado"<<endl;
            	fwrite(&xdat,sizeof(xdat),1,p);
            	getch();
   			}
   			else
   			{
   				gotoxy(42,20);cout<<"El nombre o apellido "<<xnom<<" NO se encuentra en el registro"<<endl;
               getch();
   			}
            con++;
         	fclose(p);
      	}
         if(con==0 && opcion==2)
         {
            gotoxy(42,16);cout<<"No hay datos en el registro. No se puede eliminar"<<endl;
            getch();
         }
   	}while(opcion<3);
   }
}
void Modificar(struct datos xdat[],int xi)//,struct datos xaux[],struct datos xtec[],struct datos xpro[],int *xa,int *xt,int *xp)
{
	if(xi==0) //si no hay datos
   {
   	cout<<"No hay datos en el registro. No se puede modificar"<<endl;
   	getch();
   }else
   {
		int k,res;
      char auxbs[10];
      datos temp;
      do
   	{
			clrscr();
         system("color F9");
			cout<<"             SUBMENU"<<endl;
			cout<<"   ---------------------------"<<endl;
			cout<<"|--\t1.- Codigo\t\t--|"<<endl;
			cout<<"|--\t2.- Nombre\t\t--|"<<endl;
			cout<<"|--\t3.- Volver\t\t--|"<<endl;
			cout<<"   ---------------------------\n"<<endl;
			cout<<" Ingrese el tipo de su consulta ==> "<<endl;
   		cin>>res;
      	if(res>=3)
      	{
      		break;
      	}
   		if(res==1)
      	{
         	cout<<"\n ===== CODIGOS ===== "<<endl;
            for(int j=0;j<xi;j++)
            {
            	cout<<xdat[j].cod;
               if((j+1)!=xi){
               cout<<"  ||  ";}
            }
      		cout<<"\n Ingrese el codigo del trabajador que desea modificar sus datos"<<endl;
      		cin>>auxbs;
         	for(int i=0;i<xi;i++)
         	{
         		if(strcmp(auxbs,(xdat[i].cod))==0)
            	{
            		p=fopen(nom,"r");
            		k=i;
                  datos temp;
                  temp=xdat[k];
               	cout<<"\n\n                                                       REPORTE DEL TRABAJADOR "<<endl;
   					cout<<"--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   					cout<<" COD | NOMBRES Y APELLIDOS | CATEG | SEXO | E.CIVIL | PROF./OCUP. | CARGO | S.BASICO | BONIF. | DESC.| B.RIESGO | B.CAP. | R.IMP. | S.TOTAL"<<endl;
   					cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
						printf("%5s %10s %10c %10c %11c %14s %13c %10.1f %10.1f %10.1f %10.1f %11.1f %14.1f %13.1f \n", xdat[k].cod,xdat[k].apynom,xdat[k].cat,xdat[k].sexo,xdat[k].ec,xdat[k].prof,xdat[k].cargo,xdat[k].sbasico,xdat[k].boni,xdat[k].desc,xdat[k].bonxrv,xdat[k].bonxcap,xdat[k].ri,xdat[k].tot);
   					cout<<"\n\n===== Recolectando los nuevos datos del Trabajador <"<<(k+1)<<">======"<<endl;
  	 					cout<<"Ingrese el codigo del Trabajador"<<endl;
   					cin>>xdat[k].cod;
  	 					cout<<"Ingrese el apellido y nombre del trabajador"<<endl;
   					gets(xdat[k].apynom);
   					cout<<"Ingrese la categoria del trabajador ((A)Auxiliar - (T)Tecnico - (P)Profesional)"<<endl;
   					cin>>xdat[k].cat;
   					cout<<"Ingrese el sexo del trabajador ((F)FEMENINO - (M)MASCULINO)"<<endl;
   					cin>>xdat[k].sexo;
   					cout<<"Ingrese el estado civil del trabajador ((S)SOLTERO/A - (C)CASADO/A)"<<endl;
   					cin>>xdat[k].ec;
   					cout<<"Ingrese la profesion/ocupacion del trabajador "<<endl;
   					cin>>xdat[k].prof;
   					cout<<"Ingrese el cargo del trabajador ((O)OBRERO - (A)ADMINISTRATIVO - (J)JEFE - (D)DIRECTOR)"<<endl;
   					cin>>xdat[k].cargo;
   					cout<<"Ingrese el sueldo basico del trabajador "<<endl;
   					cin>>xdat[k].sbasico;
   					cout<<"Ingrese la bonificacion del trabajador "<<endl;
   					cin>>xdat[k].boni;
   					cout<<"Ingrese el descuento del trabajador "<<endl;
   					cin>>xdat[k].desc;
   					xdat[k].tot=xdat[k].sbasico+xdat[k].boni-xdat[k].desc;
   					if(xdat[k].cargo=='O')
   					{
   						cout<<"Ingrese la bonificacion por riesgo de vida del obrero "<<endl;
   						cin>>xdat[k].bonxrv;
   						xdat[k].tot+=xdat[k].bonxrv;
   					}else{xdat[k].bonxrv=0;}
   					if(xdat[k].cat=='T')
   					{
   						cout<<"Ingrese la bonificacion por capacitacion del tecnico "<<endl;
   	   				cin>>xdat[k].bonxcap;
   	   				xdat[k].tot+=xdat[k].bonxcap;
   					}else{xdat[k].bonxcap=0;}
   					if(xdat[k].cat=='P')
   					{
   						cout<<"Ingrese la retencion de impuesto del profesional "<<endl;
   	   				cin>>xdat[k].ri;
   					}else{xdat[k].ri=0;}
   					fwrite(&xdat,sizeof(xdat),1,p);
   				}
   				else
   				{
   					cout<<"Este numero de trabajador no se encuentra en la data"<<endl;
                  getch();
   				}
   				fclose(p);
         	}
      	}
         else if(res==2)
         {
         	char nombre[20];
            cout<<"\n ===== NOMBRE/APELLIDO ===== "<<endl;
            for(int j=0;j<xi;j++)
            {
            	cout<<xdat[j].apynom;
               if((j+1)!=xi){
               cout<<"  ||  ";}
            }
         	cout<<"\nIngrese el nombre del trabajador que desea modificar sus datos"<<endl;
         	gets(nombre);
         	for(int i=0;i<xi;i++)
         	{
         		if(strcmp(nombre,(xdat[i].apynom))==0)
            	{
               	k=i;
                  temp=xdat[k];
                  p=fopen(nom,"r");
                  cout<<"\n\n                                                       REPORTE DEL TRABAJADOR "<<endl;
   					cout<<"--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   					cout<<" COD | NOMBRES Y APELLIDOS | CATEG | SEXO | E.CIVIL | PROF./OCUP. | CARGO | S.BASICO | BONIF. | DESC.| B.RIESGO | B.CAP. | R.IMP. | S.TOTAL"<<endl;
   					cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
						printf("%5s %10s %10c %10c %11c %14s %13c %10.1f %10.1f %10.1f %10.1f %11.1f %14.1f %13.1f \n", xdat[k].cod,xdat[k].apynom,xdat[k].cat,xdat[k].sexo,xdat[k].ec,xdat[k].prof,xdat[k].cargo,xdat[k].sbasico,xdat[k].boni,xdat[k].desc,xdat[k].bonxrv,xdat[k].bonxcap,xdat[k].ri,xdat[k].tot);
   					cout<<"\n\n===== Recolectando los nuevos datos del Trabajador <"<<(k+1)<<">======"<<endl;
  	 					cout<<"Ingrese el codigo del Trabajador"<<endl;
   					cin>>xdat[k].cod;
  	 					cout<<"Ingrese el apellido y nombre del trabajador"<<endl;
   					gets(xdat[k].apynom);
   					cout<<"Ingrese la categoria del trabajador ((A)Auxiliar - (T)Tecnico - (P)Profesional)"<<endl;
   					cin>>xdat[k].cat;
   					cout<<"Ingrese el sexo del trabajador ((F)FEMENINO - (M)MASCULINO)"<<endl;
   					cin>>xdat[k].sexo;
   					cout<<"Ingrese el estado civil del trabajador ((S)SOLTERO/A - (C)CASADO/A)"<<endl;
   					cin>>xdat[k].ec;
   					cout<<"Ingrese la profesion/ocupacion del trabajador "<<endl;
   					cin>>xdat[k].prof;
   					cout<<"Ingrese el cargo del trabajador ((O)OBRERO - (A)ADMINISTRATIVO - (J)JEFE - (D)DIRECTOR)"<<endl;
   					cin>>xdat[k].cargo;
   					cout<<"Ingrese el sueldo basico del trabajador "<<endl;
   					cin>>xdat[k].sbasico;
   					cout<<"Ingrese la bonificacion del trabajador "<<endl;
   					cin>>xdat[k].boni;
   					cout<<"Ingrese el descuento del trabajador "<<endl;
   					cin>>xdat[k].desc;
   					xdat[k].tot=xdat[k].sbasico+xdat[k].boni-xdat[k].desc;
   					if(xdat[k].cargo=='O')
   					{
   						cout<<"Ingrese la bonificacion por riesgo de vida del obrero "<<endl;
   						cin>>xdat[k].bonxrv;
   						xdat[k].tot+=xdat[k].bonxrv;
   					}else{xdat[k].bonxrv=0;}
   					if(xdat[k].cat=='T')
   					{
   						cout<<"Ingrese la bonificacion por capacitacion del tecnico "<<endl;
   	   				cin>>xdat[k].bonxcap;
   	   				xdat[k].tot+=xdat[k].bonxcap;
   					}else{xdat[k].bonxcap=0;}
   					if(xdat[k].cat=='P')
   					{
   						cout<<"Ingrese la retencion de impuesto del profesional "<<endl;
   	   				cin>>xdat[k].ri;
   					}else{xdat[k].ri=0;}
   					fwrite(&xdat,sizeof(xdat),1,p);
   				}
   				else
   				{
   					cout<<"El nombre del trabajador no se encuentra en la data"<<endl;
                  getch();
   				}
         	}
   		}
         fclose(p);
      }while(res<3);
	}
}
void Consultar(struct datos xdat[],int xi)
{
    int alt=0;
    if(xi==0) //si no hay datos
    {
   		cout<<"No hay datos en el registro. No se puede consultar"<<endl;
         getch();
    }
    else
    {
      do
   	{
      	clrscr();
      	system("color F9");
			cout<<"              SUBMENU"<<endl;
			cout<<"   ---------------------------"<<endl;
			cout<<"|--\t1.- Codigo\t\t--|"<<endl;
			cout<<"|--\t2.- Apellidos y Nombres\t--|"<<endl;
      	cout<<"|--\t3.- Volver\t\t--|"<<endl;
			cout<<"   ---------------------------\n"<<endl;
			cout<<" Ingrese el numero de su opcion==> ";
			cin>>alt;
         if(alt==1)
         {     //busqueda binaria
         	int mitad,inf,sup;
         	inf=0;
            sup=xi;
            int v=0;
            char f[50];
            cout<<"\n ===== CODIGOS ===== "<<endl;
            for(int j=0;j<xi;j++)
            {
            	cout<<xdat[j].cod;
               if((j+1)!=xi){
               cout<<"  ||  ";}
            }
            p=fopen(nom,"r");
            cout<<"\nIngrese el codigo el cual quiere buscar: ";
            cin>>f;
            while(inf<=sup)
            {
            	mitad=(inf+sup)/2;
               if(strcmp(xdat[mitad].cod,f)==0)
            	{                               // 0 1 2 3 4
               	v=1;                        //  2 3 4 5 6
               	break;
               }
               if(strcmp(xdat[mitad].cod,f)>0)
               {
               	sup=mitad;
                  mitad = (inf+sup)/2;
               }
               if(strcmp(xdat[mitad].cod,f)<0)
               {
       			  	inf=mitad;
                  mitad = (inf+sup)/2;
               }
            }
            if(v==1)
            {
            	fseek(p,((mitad)*sizeof(dat)),0);
               fread(&dat,sizeof(dat),1,p);
               cout<<"\n\n                                                       REPORTE DEL TRABAJADOR "<<endl;
               cout<<"--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
               cout<<" COD | NOMBRES Y APELLIDOS | CATEG | SEXO | E.CIVIL | PROF./OCUP. | CARGO | S.BASICO | BONIF. | DESC.| B.RIESGO | B.CAP. | R.IMP. | S.TOTAL"<<endl;
               cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
               cout<<xdat[mitad].cod<<"     "<<xdat[mitad].apynom<<"     "<<xdat[mitad].cat<<"     "<<xdat[mitad].sexo<<"    "<<xdat[mitad].ec<<"   "<<xdat[mitad].prof<<"    "<<xdat[mitad].cargo<<"    "<<xdat[mitad].sbasico<<"    "<<xdat[mitad].boni<<"    "<<xdat[mitad].desc<<"    "<<xdat[mitad].bonxrv<<"    "<<xdat[mitad].bonxcap<<"    "<<xdat[mitad].ri<<"    "<<xdat[mitad].tot<<endl;
            }
            else
            {
            	cout<<"El codigo "<<f<<" del trabajador no ha sido encontrado en el registro"<<endl;
               getch();
            }
            fclose(p);
         }
         if(alt==2)
         {     //busqueda indexada
         	char r[50];
            int cont=0,xn_indices=0,pos=0,ke=0;
            int indice[50];
            cout<<"\n ===== NOMBRE/APELLIDO ===== "<<endl;
            for(int j=0;j<xi;j++)
            {
            	cout<<xdat[j].apynom;
               if((j+1)!=xi){
               cout<<"  ||  ";}
            }
            cout<<"\nIngrese el nombre el cual quiere buscar: ";
            gets(r);
            cout<<"\nIngrese la cantidad de elementos por grupo: ";
            cin>>ke;
            if(xi%ke==0)
            {
            	xn_indices=xi/ke;
            }
            else
            {
     			  	xn_indices=(xi/ke)+1;
            }
            for(int j=0;j<xn_indices;j++)
            {
            	indice[j]=cont;
               cont=cont+ke;
            }
            cout<<"Los elementos del arreglo indice son "<<endl;
            for(int j=0;j<xn_indices;j++)
            {
            	cout<<indice[j]<<"  ";
            }
            cout<<endl;
            for(int j=xn_indices-1;j>=0;j--)
            {
            	if(strcmp(r,xdat[indice[j]].apynom)>0)
            	{
               	pos=indice[j];
               	break;
               }
            }
            int cont2=0;
            for(int j=pos;j<(pos+ke);j++)
            {
            	if(strcmp(r,xdat[j].apynom)==0)
               {
               	cont2++;
                  cout<<"\n\n                                                       REPORTE DEL TRABAJADOR "<<endl;
                  cout<<"--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                  cout<<"  COD | NOMBRES Y APELLIDOS | CATEG | SEXO | E.CIVIL | PROF./OCUP. | CARGO | S.BASICO | BONIF. | DESC.| B.RIESGO | B.CAP. | R.IMP. | S.TOTAL"<<endl;
                  cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                  cout<<xdat[j].cod<<"     "<<xdat[j].apynom<<"     "<<xdat[j].cat<<"     "<<xdat[j].sexo<<"    "<<xdat[j].ec<<"   "<<xdat[j].prof<<"    "<<xdat[j].cargo<<"    "<<xdat[j].sbasico<<"    "<<xdat[j].boni<<"    "<<xdat[j].desc<<"    "<<xdat[j].bonxrv<<"    "<<xdat[j].bonxcap<<"    "<<xdat[j].ri<<"    "<<xdat[j].tot<<endl;
                  fread(&dat,sizeof(dat),1,p);
               }
            }
            if(cont2==0)
            {
            	cout<<"El apellidos y nombres "<<r<<" no se encuentra en el registro"<<endl;
               getch();
            }
         }
         getch();
   	}while(alt<3);
   }
}
void Ordenar(struct datos xdat[],int xi)
{
	int alt=0;
   do
   {
		clrscr();
      system("color F9");
		cout<<"              SUBMENU"<<endl;
		cout<<"   ---------------------------"<<endl;
		cout<<"|--\t1.- Codigo\t--|"<<endl;
		cout<<"|--\t2.- Apellidos y Nombres\t--|"<<endl;
      cout<<"|--\t3.- Volver\t--|"<<endl;
		cout<<"   ---------------------------\n"<<endl;
		cout<<" Ingrese el numero de su opcion==> ";
		cin>>alt;
      if(alt>=3)
      {
      	break;
      }
      if(alt==1)
      {
			if(xi==0)//si no hay datos
   		{
   			cout<<"No hay datos en el registro. No se puede ordenar"<<endl;
   		}else
   		{
   			p=fopen(nom,"r");
   			datos temp;
   			for(int j=0;j<xi;j++)
   			{
      			for(int k=j+1;k<xi;k++)
      			{
         			if(strcmp(xdat[j].cod,xdat[k].cod)>0)
         			{
           	 			temp=xdat[j];
            			xdat[j]=xdat[k];
            			xdat[k]=temp;
         			}
      			}
   			}
   			fwrite(&xdat,sizeof(xdat),1,p);
   			cout<<"Los registros han sido ordenados segun su codigo"<<endl;
   			fclose(p);
   		}
    	}
     if(alt==2)
     {
      	if(xi==0)//si no hay datos
   		{
   			cout<<"No hay datos en el registro. No se puede ordenar"<<endl;
   		}else
   		{
   			p=fopen(nom,"r");
   			datos oca;
            int cam;
   			for(int j=0;j<xi;j++)
   			{
            	cam=j;
      			for(int k=j+1;k<xi;k++)
      			{
         			if(strcmp(xdat[j].apynom,xdat[k].apynom)>0)
         			{
           	 			cam=k;
         			}
      			}
               oca=xdat[j];
               xdat[j]=xdat[cam];
               xdat[cam]=oca;
   			}
   			fwrite(&xdat,sizeof(xdat),1,p);
   			cout<<"Los registros han sido ordenados segun el nombre y apellido de cada trabajador"<<endl;
   			fclose(p);
   		}
      }
    	getch();
   }
   while(alt<3);
}
//PARA DINAMICA
void InsertarD()
{
	p=fopen(nom,"w");
   int opcion;
	char xcod[10],xapynom[20],xcat,xsexo,xec,xprof[15],xcargo;
   float xsbasico,xboni,xdesc,xbonxrv,xbonxcap,xri,xtot;
   do
	{
		clrscr();
      system("color F9");
		cout<<"               SUBMENU"<<endl;
		cout<<"   ---------------------------"<<endl;
		cout<<"|--\t1.- Auxiliar\t--|"<<endl;
		cout<<"|--\t2.- Tecnico\t--|"<<endl;
		cout<<"|--\t3.- Profesional\t--|"<<endl;
		cout<<"|--\t4.- Volver\t--|"<<endl;
		cout<<"   ---------------------------\n"<<endl;
		cout<<" Ingrese el numero de su opcion ==> ";
		cin>>opcion;
      if(opcion>=4){break;}
   	cout<<"===== Recolectando los datos del Trabajador ======"<<endl;
   	cout<<"Ingrese el codigo del Trabajador"<<endl;
   	cin>>xcod;
   	cout<<"Ingrese el apellido y nombre del trabajador"<<endl;
   	gets(xapynom);
   	cout<<"Ingrese el sexo del trabajador ((F)FEMENINO - (M)MASCULINO)"<<endl;
   	cin>>xsexo;
   	cout<<"Ingrese el estado civil del trabajador ((S)SOLTERO/A - (C)CASADO/A)"<<endl;
   	cin>>xec;
   	cout<<"Ingrese la profesion/ocupacion del trabajador "<<endl;
   	gets(xprof);
   	cout<<"Ingrese el cargo del trabajador ((O)OBRERO - (A)ADMINISTRATIVO - (J)JEFE - (D)DIRECTOR)"<<endl;
   	cin>>xcargo;
   	cout<<"Ingrese el sueldo basico del trabajador "<<endl;
   	cin>>xsbasico;
   	cout<<"Ingrese la bonificacion del trabajador "<<endl;
   	cin>>xboni;
   	cout<<"Ingrese el descuento del trabajador "<<endl;
   	cin>>xdesc;
   	xtot=xsbasico+xboni-xdesc;
   	if(xcargo=='O')
   	{
   		cout<<"Ingrese la bonificacion por riesgo de vida del obrero "<<endl;
      	cin>>xbonxrv;
      	xtot+=xbonxrv;
   	}else{xbonxrv=0;}
   	if(opcion==2)
   	{
   		cout<<"Ingrese la bonificacion por capacitacion del tecnico "<<endl;
      	cin>>xbonxcap;
      	xtot+=xbonxcap;
   	}else{xbonxcap=0;}
   	if(opcion==3)
   	{
   		cout<<"Ingrese la retencion de impuesto del profesional "<<endl;
   		cin>>xri;
      	xtot-=xri;
   	}else{xri=0;}
   	if(opcion==1)
   	{
      	xcat='A';
   	}
   	if(opcion==2)
   	{
      	xcat='T';
   	}
   	if(opcion==3)
   	{
     		xcat='P';
   	}
      nuevo=(din *)malloc(tam);   
      strcpy(nuevo->cod,xcod);
      strcpy(nuevo->apynom,xapynom);                         
      nuevo->cat=xcat;
      nuevo->sexo=xsexo;
      nuevo->ec=xec;
      strcpy(nuevo->prof,xprof);
		nuevo->cargo=xcargo;
      nuevo->sbasico=xsbasico;
      nuevo->boni=xboni;
      nuevo->desc=xdesc;
      nuevo->bonxrv=xbonxrv;
      nuevo->bonxcap=xbonxcap;
      nuevo->ri=xri;
      nuevo->tot=xtot;
      if(comienzo==fin_lista)
      	comienzo=nuevo;
      else   
      {         
      	aux=comienzo;
         while(aux->sig!=fin_lista)
         {
         	aux=aux->sig;
         }   
         aux->sig=nuevo;
   	}  
      nuevo->sig=fin_lista;
   	fwrite(&aux,sizeof(aux),1,p);
   }
	while(opcion<4);
   fclose(p);
}
void MostrarD()
{
	if(comienzo==fin_lista)
   {
   	cout<<"No hay datos en el registro. No hay nada que mostrar"<<endl;
   	getch();
   }else
   {
   	clrscr();
   	system("color F9");
      cout<<"\n\n                                                       REPORTE DEL TRABAJADOR "<<endl;
      cout<<"--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
      cout<<" COD | NOMBRES Y APELLIDOS | CATEG | SEXO | E.CIVIL | PROF./OCUP. | CARGO | S.BASICO | BONIF. | DESC.| B.RIESGO | B.CAP. | R.IMP. | S.TOTAL"<<endl;
      cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
      int h=0;
      temp=comienzo;
      while(temp!=fin_lista)
    	{
      	if(temp->cat=='A')
      	{
         	p=fopen(nom,"r");
            cout<<(h+1)<<") ";
            printf("%5s %10s %10c %10c %11c %14s %13c %10.1f %10.1f %10.1f %10.1f %11.1f %14.1f %13.1f \n", temp->cod,temp->apynom,temp->cat,temp->sexo,temp->ec,temp->prof,temp->cargo,temp->sbasico,temp->boni,temp->desc,temp->bonxrv,temp->bonxcap,temp->ri,temp->tot);
            fclose(p);
            h++;
         }
    		temp=temp->sig;
    	}
      if(h==0)
      {
      	cout<<"No hay auxiliares en el registro. No hay nada que mostrar"<<endl;
      }
      cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
      h=0;
      temp=comienzo;
      while(temp!=fin_lista)
    	{
      	if(temp->cat=='T')
      	{
         	p=fopen(nom,"r");
            cout<<(h+1)<<") ";
            printf("%5s %10s %10c %10c %11c %14s %13c %10.1f %10.1f %10.1f %10.1f %11.1f %14.1f %13.1f \n", temp->cod,temp->apynom,temp->cat,temp->sexo,temp->ec,temp->prof,temp->cargo,temp->sbasico,temp->boni,temp->desc,temp->bonxrv,temp->bonxcap,temp->ri,temp->tot);
            fclose(p);
            h++;
         }
    		temp=temp->sig;
    	}
      if(h==0)
      {
      	cout<<"No hay tecnicos en el registro. No hay nada que mostrar"<<endl;
      }
      cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
      h=0;
      temp=comienzo;
      while(temp!=fin_lista)
    	{
      	if(temp->cat=='P')
      	{
         	p=fopen(nom,"r");
            cout<<(h+1)<<") ";
            printf("%5s %10s %10c %10c %11c %14s %13c %10.1f %10.1f %10.1f %10.1f %11.1f %14.1f %13.1f \n", temp->cod,temp->apynom,temp->cat,temp->sexo,temp->ec,temp->prof,temp->cargo,temp->sbasico,temp->boni,temp->desc,temp->bonxrv,temp->bonxcap,temp->ri,temp->tot);
            fclose(p);
            h++;
         }
    		temp=temp->sig;
    	}
      if(h==0)
      {
      	cout<<"No hay profesionales en el registro. No hay nada que mostrar"<<endl;
      }
      cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   	getch();
   }
}
void EliminarD()
{
	int opcion;
   //aux=comienzo;
   if(comienzo==0)//si no hay datos
   {
   	gotoxy(42,19);cout<<"No hay datos en el registro. No se puede eliminar"<<endl;
      getch();
   }
   else
   {
		do
		{
			clrscr();
      	system("color F9");
			gotoxy(42,10);cout<<"             SUBMENU"<<endl;
			gotoxy(42,11);cout<<"   ---------------------------"<<endl;
			gotoxy(42,12);cout<<"|--\t1.- Codigo\t\t--|"<<endl;
			gotoxy(42,13);cout<<"|--\t2.- Nombre\t\t--|"<<endl;
			gotoxy(42,14);cout<<"|--\t3.- Volver\t\t--|"<<endl;
			gotoxy(42,15);cout<<"   ---------------------------\n"<<endl;
			gotoxy(42,16);cout<<" Ingrese el tipo de su consulta ==> ";
			cin>>opcion;
      	if(opcion>2)
      	{
      		break;
      	}
      	if(opcion==1)
      	{
      		p=fopen(nom,"r");    //lista=comienzo Nodo=datos
      		char xcodi[10];
            din *h=comienzo;
            cout<<"\n ===== CODIGOS ===== "<<endl;
            while(h!=fin_lista)
            {
            	cout<<h->cod;
               h=h->sig;
               if(h!=fin_lista)
               {
               	cout<<"  ||  ";
               }
            }
      		cout<<"\nIngrese el codigo del trabajador: "<<endl;
         	gets(xcodi);
            if(comienzo!=fin_lista)
            {
            	din *a;
               din *b=fin_lista;
               a=comienzo;
               while((a!=fin_lista)&&(strcmp(a->cod,xcodi)!=0))
               {
               	b=a;
                  a=a->sig;
               }
               if(a==fin_lista) //Si no se encuentra el codigo
               {
               	cout<<"El codigo no ha sido encontrado en el registro";
               }
               else if(b==fin_lista)   //si el primero se quiere eliminar
               {
               	comienzo=comienzo->sig;
                  delete a;
                  cout<<"El registro de codigo "<<xcodi<<" ha sido eliminado"<<endl;
               }
               else  //se elimina 
               {
               	b->sig=a->sig;
                  delete a;
                  cout<<"El registro de codigo "<<xcodi<<" ha sido eliminado"<<endl;
               }
               fwrite(&b,sizeof(b),1,p);
               getch();
            }
            fclose(p);
      	}
      	//NOMBRE
      	if(opcion==2)
      	{
      		p=fopen(nom,"r");
      		char xnom[20];
            din *h=comienzo;
            cout<<"\n ===== NOMBRE/APELLIDO ===== "<<endl;
            while(h!=fin_lista)
            {
            	cout<<h->apynom;
               h=h->sig;
               if(h!=fin_lista)
               {
               	cout<<"  ||  ";
               }
            }
      		cout<<"\nIngrese el nombre del trabajador: "<<endl;
         	cin>>xnom;
         	if(comienzo!=fin_lista)
         	{
         		din *a;
            	din *b=fin_lista;
            	a=comienzo;
            	while((a!=fin_lista)&&(strcmp(a->apynom,xnom)!=0))
            	{
            		b=a;
               	a=a->sig;
            	}
            	if(a==fin_lista)
            	{
            		cout<<"El nombre y apellido no ha sido encontrado en el registro";
            	}
            	else if(b==fin_lista)
            	{
            		comienzo=comienzo->sig;
               	delete a;
               	cout<<"El registro de nombre y apellido "<<xnom<<" ha sido eliminado"<<endl;
            	}
            	else
            	{
            		b->sig=a->sig;
               	delete a;
               	cout<<"El registro de nombre y apellido "<<xnom<<" ha sido eliminado"<<endl;
            	}
               fwrite(&b,sizeof(b),1,p);
            	getch();
         	}
         	fclose(p);
         }
      }while(opcion<3);
   }
}
void ModificarD()
{
	if(comienzo==fin_lista) //si no hay datos
   {
   	gotoxy(42,19);cout<<"No hay datos en el registro. No se puede modificar"<<endl;
   	getch();
   }else
   {
		int res;
      char auxbs[10];
      char xcod[10],xapynom[20],xcat,xsexo,xec,xprof[15],xcargo;
      float xsbasico,xboni,xdesc,xbonxrv,xbonxcap,xri,xtot;
      do
   	{
			clrscr();
         system("color F9");
			gotoxy(42,10);cout<<"             SUBMENU"<<endl;
			gotoxy(42,11);cout<<"   ---------------------------"<<endl;
			gotoxy(42,12);cout<<"|--\t1.- Codigo\t\t--|"<<endl;
			gotoxy(42,13);cout<<"|--\t2.- Nombre\t\t--|"<<endl;
			gotoxy(42,14);cout<<"|--\t3.- Volver\t\t--|"<<endl;
			gotoxy(42,15);cout<<"   ---------------------------\n"<<endl;
			gotoxy(42,16);cout<<" Ingrese el tipo de su consulta ==> ";
   		cin>>res;
      	if(res>=3)
      	{
      		break;
      	}
   		if(res==1)
      	{
         	int cont=0;
            din *h=comienzo;
            gotoxy(42,17);cout<<" ===== CODIGOS ===== "<<endl;
            gotoxy(42,18);
            while(h!=fin_lista)
            {
            	cout<<h->cod;
               h=h->sig;
               if(h!=fin_lista)
               {
               	cout<<"  ||  ";
               }
            }
      		gotoxy(42,19);cout<<"Ingrese el codigo del trabajador que desea modificar sus datos";
      		cin>>auxbs;
            temp=comienzo;
            while(temp!=fin_lista)
    			{
         		if(strcmp(auxbs,temp->cod)==0)
            	{
               	p=fopen(nom,"r");
               	gotoxy(42,20);cout<<"\n\n                                                       REPORTE DEL TRABAJADOR "<<endl;
   					gotoxy(42,21);cout<<"--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   					gotoxy(42,22);cout<<" COD | NOMBRES Y APELLIDOS | CATEG | SEXO | E.CIVIL | PROF./OCUP. | CARGO | S.BASICO | BONIF. | DESC.| B.RIESGO | B.CAP. | R.IMP. | S.TOTAL"<<endl;
   					gotoxy(42,23);cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
						gotoxy(42,24);printf("%5s %10s %10c %10c %11c %14s %13c %10.1f %10.1f %10.1f %10.1f %11.1f %14.1f %13.1f \n", temp->cod,temp->apynom,temp->cat,temp->sexo,temp->ec,temp->prof,temp->cargo,temp->sbasico,temp->boni,temp->desc,temp->bonxrv,temp->bonxcap,temp->ri,temp->tot);
   					gotoxy(42,25);cout<<"\n\n===== Modificando los datos del Trabajador de codigo <"<<auxbs<<">======";
                  gotoxy(42,26);cout<<"Ingrese el codigo del Trabajador";
   					cin>>xcod;
   					gotoxy(42,27);cout<<"Ingrese el apellido y nombre del trabajador";
   					gets(xapynom);
                  gotoxy(42,28);cout<<"Ingrese la categoria del trabajador ((A)Auxiliar - (T)Tecnico - (P)Profesional)";
   					cin>>xcat;
   					gotoxy(42,29);cout<<"Ingrese el sexo del trabajador ((F)FEMENINO - (M)MASCULINO)";
   					cin>>xsexo;
   					gotoxy(42,30);cout<<"Ingrese el estado civil del trabajador ((S)SOLTERO/A - (C)CASADO/A)";
   					cin>>xec;
   					gotoxy(42,31);cout<<"Ingrese la profesion/ocupacion del trabajador ";
   					gets(xprof);
   					gotoxy(42,32);cout<<"Ingrese el cargo del trabajador ((O)OBRERO - (A)ADMINISTRATIVO - (J)JEFE - (D)DIRECTOR)";
   					cin>>xcargo;
   					gotoxy(42,33);cout<<"Ingrese el sueldo basico del trabajador ";
   					cin>>xsbasico;
   					gotoxy(42,34);cout<<"Ingrese la bonificacion del trabajador ";
   					cin>>xboni;
   					gotoxy(42,35);cout<<"Ingrese el descuento del trabajador ";
   					cin>>xdesc;
   					xtot=xsbasico+xboni-xdesc;
                  int l=0;
   					if(xcargo=='O')
   					{
   						gotoxy(42,36);cout<<"Ingrese la bonificacion por riesgo de vida del obrero ";
      					cin>>xbonxrv;
      					xtot+=xbonxrv;
                     l++;
   					}else{xbonxrv=0;}
   					if(xcat=='T')
   					{
   						gotoxy(42,37);cout<<"Ingrese la bonificacion por capacitacion del tecnico ";
      					cin>>xbonxcap;
      					xtot+=xbonxcap;
   					}else{xbonxcap=0;}
   					if(xcat=='P')
   					{
   						gotoxy(42,38);cout<<"Ingrese la retencion de impuesto del profesional ";
   						cin>>xri;
      					xtot-=xri;
   					}else{xri=0;}
                  strcpy(temp->cod,xcod);
      				strcpy(temp->apynom,xapynom);
      				temp->cat=xcat;
      				temp->sexo=xsexo;
      				temp->ec=xec;
      				strcpy(temp->prof,xprof);
						temp->cargo=xcargo;
      				temp->sbasico=xsbasico;
      				temp->boni=xboni;
      				temp->desc=xdesc;
      				temp->bonxrv=xbonxrv;
      				temp->bonxcap=xbonxcap;
      				temp->ri=xri;
      				temp->tot=xtot;
                  cont++;
   					fwrite(&temp,sizeof(temp),1,p);
                  fclose(p);
   				}
               temp=temp->sig;
            }
            if(cont==0)
            {
            	gotoxy(42,20);cout<<"El codigo de este trabajador no se encuentra en la data"<<endl;
               getch();
            }
      	}
         else if(res==2)
         {
         	char nombre[20];
            int cont=0;
            din *h=comienzo;
            gotoxy(42,17);cout<<"===== NOMBRE/APELLIDO ===== "<<endl;
            gotoxy(42,18);
            while(h!=fin_lista)
            {
            	cout<<h->apynom;
               h=h->sig;
               if(h!=fin_lista)
               {
               	cout<<"  ||  ";
               }
            }
         	gotoxy(42,19);cout<<"Ingrese el nombre del trabajador que desea modificar sus datos";
         	gets(nombre);
            temp=comienzo;
         	while(temp!=fin_lista)
    			{
         		if(strcmp(nombre,temp->apynom)==0)
            	{
            		p=fopen(nom,"r");
               	gotoxy(42,20);cout<<"\n\n                                                       REPORTE DEL TRABAJADOR "<<endl;
   					gotoxy(42,21);cout<<"--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   					gotoxy(42,22);cout<<" COD | NOMBRES Y APELLIDOS | CATEG | SEXO | E.CIVIL | PROF./OCUP. | CARGO | S.BASICO | BONIF. | DESC.| B.RIESGO | B.CAP. | R.IMP. | S.TOTAL"<<endl;
   					gotoxy(42,23);cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
						gotoxy(42,24);printf("%5s %10s %10c %10c %11c %14s %13c %10.1f %10.1f %10.1f %10.1f %11.1f %14.1f %13.1f \n", temp->cod,temp->apynom,temp->cat,temp->sexo,temp->ec,temp->prof,temp->cargo,temp->sbasico,temp->boni,temp->desc,temp->bonxrv,temp->bonxcap,temp->ri,temp->tot);
   					gotoxy(42,25);cout<<"\n\n===== Modificando los datos del Trabajador de nombre <"<<nombre<<">======";
                  gotoxy(42,26);cout<<"Ingrese el codigo del Trabajador";
   					cin>>xcod;
   					gotoxy(42,27);cout<<"Ingrese el apellido y nombre del trabajador";
   					gets(xapynom);
                  gotoxy(42,28);cout<<"Ingrese la categoria del trabajador ((A)Auxiliar - (T)Tecnico - (P)Profesional)";
   					cin>>xcat;
   					gotoxy(42,29);cout<<"Ingrese el sexo del trabajador ((F)FEMENINO - (M)MASCULINO)";
   					cin>>xsexo;
   					gotoxy(42,30);cout<<"Ingrese el estado civil del trabajador ((S)SOLTERO/A - (C)CASADO/A)";
   					cin>>xec;
   					gotoxy(42,31);cout<<"Ingrese la profesion/ocupacion del trabajador ";
   					gets(xprof);
   					gotoxy(42,32);cout<<"Ingrese el cargo del trabajador ((O)OBRERO - (A)ADMINISTRATIVO - (J)JEFE - (D)DIRECTOR)";
   					cin>>xcargo;
   					gotoxy(42,33);cout<<"Ingrese el sueldo basico del trabajador ";
   					cin>>xsbasico;
   					gotoxy(42,34);cout<<"Ingrese la bonificacion del trabajador ";
   					cin>>xboni;
   					gotoxy(42,35);cout<<"Ingrese el descuento del trabajador ";
   					cin>>xdesc;
   					xtot=xsbasico+xboni-xdesc;
   					if(xcargo=='O')
   					{
   						gotoxy(42,36);cout<<"Ingrese la bonificacion por riesgo de vida del obrero "<<endl;
      					cin>>xbonxrv;
      					xtot+=xbonxrv;
   					}else{xbonxrv=0;}
   					if(xcat=='T')
   					{
   						gotoxy(42,37);cout<<"Ingrese la bonificacion por capacitacion del tecnico "<<endl;
      					cin>>xbonxcap;
      					xtot+=xbonxcap;
   					}else{xbonxcap=0;}
   					if(xcat=='P')
   					{
   						gotoxy(42,38);cout<<"Ingrese la retencion de impuesto del profesional "<<endl;
   						cin>>xri;
      					xtot-=xri;
   					}else{xri=0;}
                  strcpy(temp->cod,xcod);
      				strcpy(temp->apynom,xapynom);
      				temp->cat=xcat;
      				temp->sexo=xsexo;
      				temp->ec=xec;
      				strcpy(temp->prof,xprof);
						temp->cargo=xcargo;
      				temp->sbasico=xsbasico;
      				temp->boni=xboni;
      				temp->desc=xdesc;
      				temp->bonxrv=xbonxrv;
      				temp->bonxcap=xbonxcap;
      				temp->ri=xri;
      				temp->tot=xtot;
                  cont++;
   					fwrite(&temp,sizeof(temp),1,p);
                  fclose(p);
   				}
               temp=temp->sig;
            }
            if(cont==0)
            {
            	gotoxy(42,20);cout<<"El nombre de este trabajador no se encuentra en la data"<<endl;
               getch();
            }
   		}
         fclose(p);
      }while(res<3);
	}
}
void ConsultarD()
{
    int alt=0;
    if(comienzo==0) //si no hay datos
    {
    	gotoxy(42,19);cout<<"No hay datos en el registro. No se puede consultar"<<endl;
      getch();
    }
    else
    {
      do
   	{
      	clrscr();
      	system("color F9");
			gotoxy(42,8);cout<<"              SUBMENU"<<endl;
			gotoxy(42,9);cout<<"   ---------------------------"<<endl;
			gotoxy(42,10);cout<<"|--\t1.- Codigo\t\t--|"<<endl;
			gotoxy(42,11);cout<<"|--\t2.- Apellidos y Nombres\t--|"<<endl;
      	gotoxy(42,12);cout<<"|--\t3.- Volver\t\t--|"<<endl;
			gotoxy(42,13);cout<<"   ---------------------------\n"<<endl;
			gotoxy(42,14);cout<<" Ingrese el numero de su opcion==> ";
			cin>>alt;
         if(alt==1)
         {
         	bool band=false;
            char f[10];
            din *h=comienzo;
            gotoxy(42,15);cout<<" ===== CODIGOS ===== "<<endl;
            gotoxy(42,16);
            while(h!=fin_lista)
            {
            	cout<<h->cod;
               h=h->sig;
               if(h!=fin_lista)
               {
               	cout<<"  ||  ";
               }
            }
            p=fopen(nom,"r");
            gotoxy(42,17);cout<<"Ingrese el codigo el cual quiere buscar: ";
            gotoxy(42,18);cin>>f;
            aux=comienzo;
            while(aux!=fin_lista)//&&(strcmp(aux->cod,f)<=0))
            {
            	if(strcmp(aux->cod,f)==0)
               {
               	temp=aux;
                  band=true;
               }
               aux=aux->sig;
            }
            if(band==true)
            {
            	gotoxy(42,19);cout<<"\n\n                                                       REPORTE DEL TRABAJADOR "<<endl;
               gotoxy(42,20);cout<<"--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
               gotoxy(42,21);cout<<" COD | NOMBRES Y APELLIDOS | CATEG | SEXO | E.CIVIL | PROF./OCUP. | CARGO | S.BASICO | BONIF. | DESC.| B.RIESGO | B.CAP. | R.IMP. | S.TOTAL"<<endl;
               gotoxy(42,22);cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
               gotoxy(42,23);cout<<temp->cod<<"     "<<temp->apynom<<"     "<<temp->cat<<"     "<<temp->sexo<<"    "<<temp->ec<<"   "<<temp->prof<<"    "<<temp->cargo<<"    "<<temp->sbasico<<"    "<<temp->boni<<"    "<<temp->desc<<"    "<<temp->bonxrv<<"    "<<temp->bonxcap<<"    "<<temp->ri<<"    "<<temp->tot<<endl;
            }
            else
            {
            	gotoxy(42,19);cout<<"El codigo "<<f<<" del trabajador no ha sido encontrado en el registro"<<endl;
            }
            fclose(p);
            getch();
         }
         if(alt==2)
         {
         	bool band=false;
            char r[50];
            p=fopen(nom,"r");
            din *h=comienzo;
            gotoxy(42,15);cout<<" ===== NOMBRES/APELLIDOS ===== "<<endl;
            gotoxy(42,16);
            while(h!=fin_lista)
            {
            	cout<<h->apynom;
               h=h->sig;
               if(h!=fin_lista)
               {
               	cout<<"  ||  ";
               }
            }
            gotoxy(42,17);cout<<"Ingrese el nombre el cual quiere buscar: ";
            gets(r);
            aux=comienzo;
            while(aux!=fin_lista)//&&(strcmp(aux->apynom,r)<=0))
            {
            	if(strcmp(aux->apynom,r)==0)
               {
               	temp=aux;
                  band=true;
               }
               aux=aux->sig;
            }
            if(band==true)
            {
            	gotoxy(42,18);cout<<"\n\n                                                       REPORTE DEL TRABAJADOR "<<endl;
               gotoxy(42,19);cout<<"--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
               gotoxy(42,20);cout<<" COD | NOMBRES Y APELLIDOS | CATEG | SEXO | E.CIVIL | PROF./OCUP. | CARGO | S.BASICO | BONIF. | DESC.| B.RIESGO | B.CAP. | R.IMP. | S.TOTAL"<<endl;
               gotoxy(42,21);cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
               gotoxy(42,22);cout<<temp->cod<<"     "<<temp->apynom<<"     "<<temp->cat<<"     "<<temp->sexo<<"    "<<temp->ec<<"   "<<temp->prof<<"    "<<temp->cargo<<"    "<<temp->sbasico<<"    "<<temp->boni<<"    "<<temp->desc<<"    "<<temp->bonxrv<<"    "<<temp->bonxcap<<"    "<<temp->ri<<"    "<<temp->tot<<endl;
            }
            else
            {
            	gotoxy(42,18);cout<<"El apellidos y nombres "<<r<<" no se encuentra en el registro"<<endl;
            }
            getch();
         }
   	}while(alt<3);
   }
} 
void OrdenarD()
{
	int alt=0;
   do
   {
		clrscr();
      system("color F9");
		gotoxy(42,8);cout<<"              SUBMENU"<<endl;
		gotoxy(42,9);cout<<"   ---------------------------"<<endl;
		gotoxy(42,10);cout<<"|--\t1.- Codigo\t--|"<<endl;
		gotoxy(42,11);cout<<"|--\t2.- Apellidos y Nombres\t--|"<<endl;
      gotoxy(42,12);cout<<"|--\t3.- Volver\t--|"<<endl;
		gotoxy(42,13);cout<<"   ---------------------------\n"<<endl;
		gotoxy(42,14);cout<<" Ingrese el numero de su opcion ==> ";
		cin>>alt;
      if(alt>=3)
      {
      	break;
      }
      if(alt==1)
      {
			if(comienzo==0)//si no hay datos
   		{
   			gotoxy(42,15);cout<<"No hay datos en el registro. No se puede ordenar"<<endl;
   		}else
   		{
            char t[15];
   			p=fopen(nom,"r");
   			din *i=comienzo;
   			while(i!=fin_lista)
   			{
            	din *j=i->sig;
      			while(j!=fin_lista)
      			{
         			if(strcmp(i->cod,j->cod)>0)
         			{
                  	strcpy(t,j->cod);
            			strcpy(j->cod,i->cod);
            			strcpy(i->cod,t);
         			}
                  j=j->sig;
      			}
               i=i->sig;
   			}
   			fwrite(&comienzo,sizeof(comienzo),1,p);
   			gotoxy(42,15);cout<<"Los registros han sido ordenados segun su codigo"<<endl;
   			fclose(p);
   		}
    	}
     	if(alt==2)
     	{
      	if(comienzo==0)//si no hay datos
   		{
   			gotoxy(42,15);cout<<"No hay datos en el registro. No se puede ordenar"<<endl;
   		}else
   		{
   			p=fopen(nom,"r");
   			din *i=comienzo;
            char t[15];
   			while(i!=fin_lista)
   			{
            	din *j= i->sig;
      			while(j!=fin_lista)
      			{
         			if(strcmp(i->apynom,j->apynom)>0)
         			{
                  	strcpy(t,j->apynom);
            			strcpy(j->apynom,i->apynom);
            			strcpy(i->apynom,t);
         			}
                  j=j->sig;
      			}
               i=i->sig;
   			}
   			fwrite(&comienzo,sizeof(comienzo),1,p);
   			gotoxy(42,15);cout<<"Los registros han sido ordenados segun el nombre y apellido de cada trabajador"<<endl;
   			fclose(p);
   		}
      }
    getch();
   }
   while(alt<3);
}
