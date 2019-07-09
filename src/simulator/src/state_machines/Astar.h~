#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ros/package.h>

/*typedef struct conection_
{
	int node;
	float cost;
}  conection;

typedef struct nodo_
{
	char flag;
	int num_node;
	float x;
	float y;
	int num_conections;
	conection conections[100];

	int parent;
	float acumulado;
}  nodo;
*/
/*nodo nodes[250];
int num_nodes = 0;
*/
// it reads the file that conteins the environment description
/*int read_nodes(char *file)
{
	FILE *fp;

	char data[ 100 ];
	int i=0;
	int flg = 0;
	float tmp;
	float dimensions_room_x,dimensions_room_y;


	int node_index,node_connection,cost;

	fp = fopen(file,"r"); 
	 
	if( fp == NULL )
	{
		sprintf(data, "File %s does not exists\n", file);
		printf("File %s does not exists\n", file);
		return(0);
	}
	//printf("World environment %s \n",file);

	while( fscanf(fp, "%s" ,data) != EOF)
	{
		if( strcmp(";(", data ) == 0 )
		{
			flg = 1;
			while(flg)
			{
				fscanf(fp, "%s", data);
				sscanf(data, "%f", &tmp);
				if(strcmp(")", data) == 0) flg = 0;
			}
		}
		else if((strcmp("node", data ) == 0) && ( flg == 0 ) )
		{
			//( node 0 0.309586 0.61346 )
			fscanf(fp, "%s" ,data);
			nodes[i].num_node = atoi(data);
			fscanf(fp, "%s" ,data);
			nodes[i].x = atof(data);
			fscanf(fp, "%s" ,data);
			nodes[i++].y = atof(data);
		}
		else if((strcmp("connection", data ) == 0) && ( flg == 0 ) )
		{
			//( node 0 0.309586 0.61346 )
			//( connection 0 4 0.112605 )
			fscanf(fp, "%s" ,data);
			node_index = atoi(data);
			
			fscanf(fp, "%s" ,data);
			node_connection = atoi(data);

			nodes[node_index].conections[nodes[node_index].num_conections].node = node_connection;

			fscanf(fp, "%s" ,data);
			nodes[node_index].conections[nodes[node_index].num_conections].cost = atof(data);
			nodes[node_index].num_conections++;
		}
	}
	fclose(fp);
	return i;
}



void printNode(int i)
{
	   //printf("\n\n");
   	//printf("# %d  x   %f y %f\n",nodes[i].num_node,nodes[i].x,nodes[i].y );
   	//printf("flag: %c parent: %d   acumulado: %f  \n",nodes[i].flag,nodes[i].parent,nodes[i].acumulado  );
   	//printf("num_conections %d \n",nodes[i].num_conections);
   	for(int j=0 ; j < nodes[i].num_conections; j++  )
   		printf(     "%d  %f \n",nodes[i].conections[j].node,nodes[i].conections[j].cost );
  
}*/

int openNodes[250];
int openCounter = 0;
int closedNodes[250];
int closedCounter = 0;
float bestNode;
int idBestNode;
float costo(int ini, int fin){
	float xdist = nodes[fin].x-nodes[ini].x;
	float ydist = nodes[fin].y-nodes[ini].y;
	return sqrt((xdist*xdist)+(ydist*ydist));	
}
int obj;
float heuristic(int nd){
	return costo(nd,obj);
}

void Astar_algorithm(int D ,int L)
{
	printf("Iniciamos A* en %d",L);
	obj = D;
	openNodes[0] = L;
	nodes[L].acumulado = 0;
	nodes[L].flag = 'Y';
	openCounter = 1;
	bool goal = false;	
	
	while(!goal){
		for(int i = 0; i<openCounter; i++){
			if(openNodes[i] == D)	goal = true;
		}
		if(!goal){
			//calcula mejor nodo de los abiertos

			idBestNode = 0;			
			bestNode = nodes[openNodes[0]].acumulado+heuristic(openNodes[0]);

			printf("Lista de abiertos:\n");
			printf(" %i ",openNodes[0]);

			for(int i = 1; i<openCounter; i++){
				printf(" %i ",openNodes[i]);
				float cost = nodes[openNodes[i]].acumulado+heuristic(openNodes[i]);
				if(cost< bestNode){
					idBestNode = i;
					bestNode = cost;
				}
			}
			printf("\n");
			//getchar();
			printf("\nEl mejor nodo es: %i",openNodes[idBestNode]);
			//del mejor nodo abre a los hijos
			int nuevos = 0;
			for(int i = 0; i<nodes[openNodes[idBestNode]].num_conections;i++){
				if(nodes[nodes[openNodes[idBestNode]].conections[i].node].flag == 'N'){				
				openNodes[nuevos+openCounter] = nodes[openNodes[idBestNode]].conections[i].node;
				nodes[nodes[openNodes[idBestNode]].conections[i].node].acumulado = nodes[openNodes[idBestNode]].acumulado +costo(openNodes[idBestNode],nodes[openNodes[idBestNode]].conections[i].node); 
				nodes[nodes[openNodes[idBestNode]].conections[i].node].flag = 'Y';
				nodes[nodes[openNodes[idBestNode]].conections[i].node].parent = openNodes[idBestNode];
				nuevos++;
				}
			}
			openCounter += nuevos;
			//sacar en nodo que abrimos de la lista de abiertos
			for (int i = idBestNode ; i<openCounter ; i++){
				openNodes[i] = openNodes[i+1];	
			}	
			openCounter--;
		}

	}
	//getchar();
	int actual = D;
	printf("\n++++++++++++++++++++++++++++++++++++++++++++\n");
	while(actual != L){
		printf(" %d ",actual);
		actual = nodes[actual].parent;	
	}	
	printf(" %d ",actual);
	printf("\n++++++++++++++++++++++++++++++++++++++++++++\n");
	//getchar();
	/*
	int menor,flagOnce;
	int contador=0;
	while(nodes[L].flag!='Y')
	{	//if(contador++ ==2)
		//	break;
		for(int j=0 ; j < nodes[D].num_conections; j++  )
   		{
   			if(nodes[nodes[D].conections[j].node].flag == 'N')
   				{
   					nodes[nodes[D].conections[j].node].acumulado = nodes[D].acumulado + nodes[D].conections[j].cost;
   					nodes[nodes[D].conections[j].node].parent = D;
   					nodes[nodes[D].conections[j].node].flag = 'P';
   					//printf("Nuevo\n");
   					//printNode(nodes[D].conections[j].node);
   				}	
   			else if( nodes[nodes[D].conections[j].node].flag == 'P' )
   			{
   				if( nodes[nodes[D].conections[j].node].acumulado > nodes[D].acumulado + nodes[D].conections[j].cost)
   				{
   					nodes[nodes[D].conections[j].node].acumulado = nodes[D].acumulado + nodes[D].conections[j].cost;
   					nodes[nodes[D].conections[j].node].parent = D;
   				}
   				//printf("Viejo\n");
   				//	printNode(nodes[D].conections[j].node);
   				
   			}

   		}
   		nodes[D].flag = 'Y';
   		menor = 0;
   		flagOnce = 1;
   		for(int j = 1; j < num_nodes ; j++)
   		{
   			if(nodes[j].flag == 'P')
   			{
   				if(flagOnce)
   				{
   					menor = j;
   					flagOnce = 0;
   				}
   				else if( nodes[menor].acumulado > nodes[j].acumulado )
   				{
   					menor = j;
   				}
   			}	
   		}
   		D = menor;
	}*/
}

int Astar(float rx ,float ry ,float lx ,float ly, char *world_name,step *steps )
{
   char archivo[150];
   int i;
   int start = 0;
   int goal = 0;
   //"../data/obstacles/obstacles.top";
   std::string paths = ros::package::getPath("simulator");
   strcpy(archivo,paths.c_str());
   strcat(archivo,"/src/data/");
   strcat(archivo,world_name);
   strcat(archivo,"/");
   strcat(archivo,world_name);
   strcat(archivo,".top");

   for( i=0; i<200; i++)
   {
   		nodes[i].flag='N';
   		nodes[i].num_conections = 0;
   		nodes[i].parent = -1;
   		nodes[i].acumulado = 0;
   }
   num_nodes=read_nodes(archivo);
   //printf("Numero de nodos : %d \n",num_nodes;


   for(i = 1; i < num_nodes; i++)
   {
   		if ( sqrt(pow( nodes[i].x - rx ,2) + pow( nodes[i].y - ry ,2)) < sqrt( pow( nodes[start].x - rx ,2) + pow( nodes[start].y - ry ,2)) )
   		{	//	printf("r-n : %d Distancia %f  Node x %f  node y %f   rx %f  ry%f \n",i,sqrt(pow( nodes[i].x - rx ,2) + pow( nodes[i].y - ry ,2)),nodes[i].x,nodes[i].y,rx,ry  );
   			start = i;
   		}
   		if (sqrt(pow( nodes[i].x - lx ,2) + pow( nodes[i].y - ly ,2)) < sqrt(pow( nodes[goal].x - lx ,2) + pow( nodes[goal].y - ly ,2) ) )
   			goal = i;
   }

//printf("Start: %d Goal %d \n",start ,goal );

/*
   for(int i=0; i<num_nodes; i++)
   {
   	printf("# %d  x   %f y %f\n",nodes[i].num_node,nodes[i].x,nodes[i].y );
   	printf("num_conections %d \n",nodes[i].num_conections);
   	for(int j=0 ; j < nodes[i].num_conections; j++  )
   		printf(     "%d  %f \n",nodes[i].conections[j].node,nodes[i].conections[j].cost );
   }
*/
   Astar_algorithm (goal ,start); 
   
   int padre = start;


  // printf("\n");
   i=0;
   int reverselist[100];
   int list[100];
   int countReverse = 0;
   int actual = goal;
   printf("\n++++++++++++++++++++++++++++++++++++++++++++\n");
   while(actual != start){
	reverselist[countReverse] = actual;
	countReverse++;	
	printf(" %d ",actual);
	actual = nodes[actual].parent;	
   	
   }	
   reverselist[countReverse] = actual;
   countReverse++;
   printf(" %d *%d*",actual,countReverse);
   printf("\n++++++++++++++++++++++++++++++++++++++++++++\n");
   for(int i = 0; i<countReverse;i++){   	
	list[i] = reverselist[countReverse-i-1];
	steps[i].node = list[i];
	steps[i].x = nodes[list[i]].x;
	steps[i].y = nodes[list[i]].y;
   	printf(" %d ",list[i]);
   }
   printf("\n++++++++++++++++++++++++++++++++++++++++++++\n");
   /*while( padre != -1)
   {
   	 //printf(" %d ",padre);
   	 steps[i].node = nodes[padre].num_node;
   	// printf("nombre:%d ",nodes[padre].num_node);
   	 steps[i].x = nodes[padre].x;
   	 steps[i++].y = nodes[padre].y;
   	 padre= nodes[padre].parent;
   }*/
  // printf("\n");
	return 0;
} 
