#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct conection_
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

nodo nodes[250];
int num_nodes = 0;

// it reads the file that conteins the environment description
int read_nodes(char *file)
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
	printf("\n\n");
   	printf("# %d  x   %f y %f\n",nodes[i].num_node,nodes[i].x,nodes[i].y );
   	printf("flag: %c parent: %d   acumulado: %f  \n",nodes[i].flag,nodes[i].parent,nodes[i].acumulado  );
   	printf("num_conections %d \n",nodes[i].num_conections);
   	for(int j=0 ; j < nodes[i].num_conections; j++  )
   		printf(     "%d  %f \n",nodes[i].conections[j].node,nodes[i].conections[j].cost );
  
}


int stack[250];
int sp=0;
void push(int v){stack[sp++] = v;}
void pop(){sp--;}
void print_stack(){
	printf("\nstack: ");
    for(int i=0; i < sp; i++)
    {
    	printf(" %d ",stack[i]);
    }
    printf("\n");
}


int actualLayer[250];
int altam=0;
int newLayer[250];
int nltam=0;
int idGoal;
void bfs(int D ,int L)
{
	printf("Hola roger");
	int node_actual = D;
	bool goal = false;
	int acumulados = 0;
	actualLayer[0] = D;
	altam = 1;

	while(!goal){
		//condicion de victoria
		for(int i = 0; i<altam;i++)
		{
			if(nodes[actualLayer[i]].num_node == L){
				goal = true;
				idGoal =i;
			}
		}
		if(!goal){
			acumulados = 0;
			for(int i=0; i<altam;i++)
			{
				for(int j=acumulados; j<acumulados+nodes[actualLayer[i]].num_conections;j++)
				{
					if(nodes[nodes[actualLayer[i]].conections[j].node].flag == 'N'){
						newLayer[j] = nodes[actualLayer[i]].conections[j].node;
						acumulados++;
						nodes[nodes[actualLayer[i]].conections[j].node].flag = 'Y';
					}
					
				}
			}
			nltam = acumulados;
			for(int i = 0; i<nltam;i++) actualLayer[i] = newLayer[i];
			altam = nltam;
		
		}		
	}
	//encuentra ruta
	int reverseStack[250];
	int crs=0;
	int actualNode = nodes[actualLayer[idGoal]].num_node; 
	while(actualNode != D)
	{
		reverseStack[crs] = actualNode;	
		actualNode = nodes[actualNode].parent;
		crs++;
	}
	sp = 0;
	for(int i = crs; i>0; i--)
	{
		push(reverseStack[i]);
	}
}

int main(int argc, char ** argv)
{
   char archivo[]="../data/obstacles/obstacles.top";
   
   for(int i=0; i<200; i++)
   {
   		nodes[i].flag='N';
   		nodes[i].num_conections = 0;
   		nodes[i].parent = -1;
   		nodes[i].acumulado = 0;
   }
   printf("NUmero de nodos #: %d \n",num_nodes=read_nodes(archivo));

   //for(int i=0; i<num_nodes; i++)
   //	printNode(i);
  
  printf("%d %d \n",atoi(argv[1]),atoi(argv[2]) );
   bfs(atoi(argv[1]),atoi(argv[2]));
   printf("Final Stack\n");
   print_stack();
	return 0;
} 
