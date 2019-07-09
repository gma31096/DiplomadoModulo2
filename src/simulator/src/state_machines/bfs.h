/***********************************************
*                                              *
*      bfs.h			               *
*                                              *
*                           *
*                                              *
*              Bio-Robotics Laboratory         *
*              UNAM, 2019                      *
*                                              *
*                                              *
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ros/package.h>

/*int stack[250];
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
}*/
int actualLayer[250];
int altam=0;
int newLayer[250];
int nltam=0;
int idGoal;
void bfs_algorithm(int D ,int L)
{
	int menor,flagOnce;
	int contador=0;
	int node_actual = D;
	int flagPush;
	bool goal = false;
	int acumulados = 0;
	actualLayer[0] = D;
	altam = 1;
	nodes[D].flag = 'Y';
	printf("%d \n",D);
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
			int offset=0;
			for(int i=0; i<altam;i++)
			{
				//printf("Exprorando a: %d Hijos %d offset: %d \n",nodes[actualLayer[i]].num_node,acumulados+nodes[actualLayer[i]].num_conections,offset);
				for(int j=0; j<nodes[actualLayer[i]].num_conections;j++)
				{
					if(nodes[nodes[actualLayer[i]].conections[j].node].flag == 'N'){
						newLayer[acumulados+offset] = nodes[actualLayer[i]].conections[j].node;
						nodes[newLayer[acumulados+offset]].parent = nodes[actualLayer[i]].num_node;
						nodes[nodes[actualLayer[i]].conections[j].node].flag = 'Y';
						//printf("%d ",nodes[actualLayer[i]].conections[j].node);
						acumulados++;
					}
				}
				offset += acumulados;
				acumulados = 0;
			}
			//printf("\n");
			//getchar();
			nltam = offset;
			for(int i = 0; i<nltam;i++) {
				actualLayer[i] = newLayer[i];
				printf("%d ",actualLayer[i]);			
			}
			printf("\n ");
			altam = nltam;
		
		}	
		//printf("------------------------------------------------- %d\n",int(goal));	
	}
	//encuentra ruta
	int reverseStack[250];
	int crs=0;
	int actualNode = nodes[actualLayer[idGoal]].num_node; 
	printf("\nya llegamos al objetivo\n");
	while(actualNode != D)
	{
		//printf("%d ",actualNode);
		//printf("%d\n",nodes[actualNode].parent);
		reverseStack[crs] = actualNode;	
		actualNode = nodes[actualNode].parent;
		crs++;
	}
	reverseStack[crs] = actualNode;
	printf("\n-------------------------------\n");
	//getchar();
	sp = 0;
	for(int i = crs; i>=0; i--)
	{
		printf("%d ",reverseStack[i]);	
		push(reverseStack[i]);
	}
	printf("\n");
}




int bfs(float rx ,float ry ,float lx ,float ly, char *world_name,step *steps )
{
	//char archivo[]="../data/obstacles/obstacles.top";
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


   for(int i=0; i<200; i++)
   {
   		nodes[i].flag='N';
   		nodes[i].num_conections = 0;
   		nodes[i].parent = -1;
   		nodes[i].acumulado = 0;
   }
   num_nodes=read_nodes(archivo);
   //printf("NUmero de nodos #: %d \n",num_nodes);
   for(i = 1; i < num_nodes; i++)
   {
   		if ( sqrt(pow( nodes[i].x - rx ,2) + pow( nodes[i].y - ry ,2)) < sqrt( pow( nodes[start].x - rx ,2) + pow( nodes[start].y - ry ,2)) )
   		{	//	printf("r-n : %d Distancia %f  Node x %f  node y %f   rx %f  ry%f \n",i,sqrt(pow( nodes[i].x - rx ,2) + pow( nodes[i].y - ry ,2)),nodes[i].x,nodes[i].y,rx,ry  );
   			start = i;
   		}
   		if (sqrt(pow( nodes[i].x - lx ,2) + pow( nodes[i].y - ly ,2)) < sqrt(pow( nodes[goal].x - lx ,2) + pow( nodes[goal].y - ly ,2) ) )
   			goal = i;
   }
   //for(int i=0; i<num_nodes; i++)
   //	printNode(i);
  
   //printf("%d %d \n",atoi(argv[1]),atoi(argv[2]) );
   bfs_algorithm(start,goal);

   //printf("Final Stack\n");
   //print_stack();


    for(int i=0; i < sp; i++)
    {
    	//printf(" %d ",stack[i]);
    	steps[i].node = nodes[stack[i]].num_node;
	   	steps[i].x = nodes[stack[i]].x;
	   	steps[i].y = nodes[stack[i]].y;
    }
    //printf("\n");


	return 0;
} 
