#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_POLYGONS 100
#define NUM_MAX_VERTEX 10
#define STRSIZ 300
#define SIZE_LINE 10000

typedef struct Vertex_ {
        float x;
        float y;
} Vertex;

typedef struct Polygon_ {
        char    name[ STRSIZ ];
        char    type[ STRSIZ ];
        int     num_vertex;
        Vertex  vertex[NUM_MAX_VERTEX];
        Vertex  min,max;
} Polygon;

Polygon polygons_wrl[100];
int num_polygons_wrl = 0;

// it reads the file that conteins the environment description
int ReadPolygons(char *file,Polygon *polygons){

	FILE *fp;
	char data[ STRSIZ ];
	int i;
	int num_poly = 0;
	int flg = 0;
	float tmp;
	float dimensions_room_x,dimensions_room_y;

	fp = fopen(file,"r"); 
	 
	if( fp == NULL )
	{
		sprintf(data, "File %s does not exists\n", file);
		printf("File %s does not exists\n", file);
		exit(0);
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
		else if((strcmp("polygon", data ) == 0) && ( flg == 0 ) )
		{
			fscanf(fp, "%s", data);
			strcpy(polygons[num_poly].type, data);
			fscanf(fp,"%s", data);
			strcpy(polygons[num_poly].name, data);
			i = 0;
			flg = 1;

			polygons[num_poly].max.x = 0;
			polygons[num_poly].max.y = 0;
			polygons[num_poly].min.x = 9999;
			polygons[num_poly].min.y = 9999;

			while(flg)
			{
				fscanf(fp,"%s",data);	
				if(strcmp(")",data) == 0) 
				{
					polygons[num_poly].num_vertex = i - 1;
					polygons[num_poly].vertex[i].x = polygons[num_poly].vertex[1].x; // to calculate intersecction range
					polygons[num_poly].vertex[i].y = polygons[num_poly].vertex[1].y; // the first vertex its repeated on the last
					num_poly++;
					flg = 0;
				}
				else
				{
					sscanf(data, "%f", &tmp);
					polygons[num_poly].vertex[i].x = tmp;
					fscanf(fp, "%s", data);
					sscanf(data, "%f", &tmp);
					polygons[num_poly].vertex[i].y = tmp;
					
					if(polygons[num_poly].vertex[i].x > polygons[num_poly].max.x)  polygons[num_poly].max.x = polygons[num_poly].vertex[i].x;
					if(polygons[num_poly].vertex[i].y > polygons[num_poly].max.y)  polygons[num_poly].max.y = polygons[num_poly].vertex[i].y;
					if(polygons[num_poly].vertex[i].x < polygons[num_poly].min.x)  polygons[num_poly].min.x = polygons[num_poly].vertex[i].x;
					if(polygons[num_poly].vertex[i].y < polygons[num_poly].min.y)  polygons[num_poly].min.y = polygons[num_poly].vertex[i].y;
	
					//printf("polygon vertex %d x %f y %f\n",i,polygons[num_poly].vertex[i].x,polygons[num_poly].vertex[i].y);
					i++;
				}
			}
		}
		else if(strcmp("dimensions", data) == 0  && (flg == 0) )
		{
			fscanf(fp, "%s", data);
			fscanf(fp, "%s", data);
			sscanf(data, "%f", &dimensions_room_x);
			fscanf(fp, "%s", data);
			sscanf(data, "%f", &dimensions_room_y);
			//printf("dimensions x %f y %f\n",dimensions_room_x,dimensions_room_y);
		}
	}
	fclose(fp);
	return num_poly;
}

void read_environment(char *file, int debug)
{
 	int i;                                                                            
	int j;

	/* it reads the polygons */
	strcpy(polygons_wrl[0].name, "NULL");
	if(debug == 1) printf("\nEnvironment file: %s\n", file);
	num_polygons_wrl = ReadPolygons(file, polygons_wrl);
	                                                                                                                                                       
	// it prints the polygons
	if(debug == 1)
	for(i = 0; i < num_polygons_wrl; i++)
	{
		//printf("\npolygon[%d].name=%s\n",i,polygons_wrl[i].name);
		//printf("polygon[%d].type=%s\n",i,polygons_wrl[i].type);
		//printf("Num vertex  polygon[%d].num_vertex=%d\n",i,polygons_wrl[i].num_vertex);
	    //printf("max x,y = (%f, %f)  min x,y = (%f, %f) \n", polygons_wrl[i].max.x, polygons_wrl[i].max.y, polygons_wrl[i].min.x, polygons_wrl[i].min.y);
	    printf("self.w.create_rectangle(%f* self.canvasX/2, (self.canvasY-( %f* self.canvasY )/2) ,  (%f* self.canvasX)/2, (self.canvasY-(%f* self.canvasX)/2), outline='#000000', width=1)\n", polygons_wrl[i].max.x, polygons_wrl[i].max.y, polygons_wrl[i].min.x, polygons_wrl[i].min.y);
		for(j = 0; j < polygons_wrl[i].num_vertex+1 ; j++)
		{
		//	printf("polygon[%d].vertex[%d] x=%f y=%f\n", i, j, polygons_wrl[i].vertex[j].x, polygons_wrl[i].vertex[j].y);
			//printf("polygon[%d].line[%d] m=%f b=%f\n", i, j, polygons_wrl[i].line[j].m, polygons_wrl[i].line[j].b);
		}
	}
}

float pDistance(float x,float y,float x1,float y1,float x2,float y2) {

  float A = x - x1;
  float B = y - y1;
  float C = x2 - x1;
  float D = y2 - y1;

  float dot = A * C + B * D;
  float len_sq = C * C + D * D;
  float param = -1;
  float dx,dy;
  float  xx, yy;

  if (len_sq != 0) //in case of 0 length line
      param = dot / len_sq;

  if (param < 0) {
    xx = x1;
    yy = y1;
  }
  else if (param > 1) {
    xx = x2;
    yy = y2;
  }
  else {
    xx = x1 + param * C;
    yy = y1 + param * D;
  }

   dx = x - xx;
   dy = y - yy;
   float aux =(dx * dx + dy * dy );

  return sqrt( aux );
}


int sat(float robot_x, float robot_y, float robot_r)
{
	int i,j;
	Vertex r_max;
	Vertex r_min;

	r_max.x = robot_x + robot_r; r_max.y = robot_y + robot_r;
	r_min.x = robot_x - robot_r; r_min.y = robot_y - robot_r;

	for(i = 0; i < num_polygons_wrl; i++)
		if( (r_min.x < polygons_wrl[i].max.x && polygons_wrl[i].max.x <   r_max.x) || ( r_min.x < polygons_wrl[i].min.x && polygons_wrl[i].min.x < r_max.x)   )
			if( (r_min.y < polygons_wrl[i].max.y && polygons_wrl[i].max.y < r_max.y) || ( r_min.y < polygons_wrl[i].min.y && polygons_wrl[i].min.y < r_max.y)   )
				for(int j = 0; j < polygons_wrl[i].num_vertex; j++)
		 			if( pDistance(robot_x, robot_y, polygons_wrl[i].vertex[j].x, polygons_wrl[i].vertex[j].y, polygons_wrl[i].vertex[j + 1].x, polygons_wrl[i].vertex[j + 1].y) <= robot_r ) 
						printf("******** Si esta intersectado :o\n");	
	return 0;
}

int main()
{
	char wrl_name[50];
	strcpy(wrl_name,"random_1.wrl");
	
	read_environment(wrl_name,1);
	float xs=1;
	float ys=1;
	float rs=.2;
	printf("self.w.create_rectangle(%f* self.canvasX/2, (self.canvasY-( %f* self.canvasY )/2) ,  (%f* self.canvasX)/2, (self.canvasY-(%f* self.canvasX)/2), outline='#000000', width=1)\n",xs+rs ,ys+rs,xs-rs,ys-rs);
	printf("self.w.create_oval(%f* self.canvasX/2, (self.canvasY-( %f* self.canvasY )/2) ,  (%f* self.canvasX)/2, (self.canvasY-(%f* self.canvasX)/2), outline='#000000', width=1)\n",xs+rs ,ys+rs,xs-rs,ys-rs);
	
	int num_vertex;
	int index[10];
	sat(xs,ys,rs);
	//printf("Distancia %f \n", pDistance(3, 5, 4, 5, 6, 7) );	
	return 0;
}