from Tkinter import *
from tkFont import Font
import threading
import ttk
import time
import math
import Image
import ImageDraw
import tkMessageBox
 

class MobileRobotSimulator(threading.Thread):
	
	def __init__(self):
		threading.Thread.__init__(self)
		
		self.stopped = False 

		self.mapX = 0
		self.mapY = 0

		self.canvasX= 600
		self.canvasY= 600
		
		self.flagF=True

		self.robotAngle=0
		self.robotX=200
		self.robotY=200

		self.p_giro=0
		self.p_distance=0
		
		self.polygonMap = []
		self.nodes_image = None
		self.light=-1
		self.robot=-1

		self.flagOnce=False

		self.light_x = 0
		self.light_y = 0
		self.startFlag = False

		self.lasers = []
		self.sensors_value = [1024];
		for i in range(1023):
			self.sensors_value.append(0)

		self.graph_list = [200]
		for i in range(200):
			self.graph_list.append(0)
		self.start()


	def kill(self):
		self.root.quit()
		self.stopped = True


	def get_parameters(self):
		parameters = []

		try:
			parameters.append(float(self.entryPoseX.get()))
		except ValueError:
			parameters.append(0.0)
		try:
			parameters.append(float(self.entryPoseY.get()))
		except ValueError:
			parameters.append(0.0)
		try:
			parameters.append(float(self.entryAngle.get()))
		except ValueError:
			parameters.append(0.0)
		try:
			parameters.append(float(self.entryRadio.get()))
		except ValueError:
			parameters.append(0.0)
		try:
			parameters.append( float(self.entryAdvance.get()))
		except ValueError:
			parameters.append(0.0)
		try:
			parameters.append( float(self.entryTurnAngle.get()))
		except ValueError:
			parameters.append(0.0)
		try:
			parameters.append( int(self.entryNumSensors.get()))
		except ValueError:
			parameters.append(0)
		try:
			parameters.append( float(self.entryOrigin.get()))
		except ValueError:
			parameters.append(0.0)
		try:
			parameters.append( float(self.entryRange.get()))
		except ValueError:
			parameters.append(0.0)
		try:
			parameters.append( float(self.entryValue.get()))
		except ValueError:
			parameters.append(0.0)
		try:
			parameters.append( str(self.entryFile.get()))
		except ValueError:
			parameters.append("NOT FOUND")
		try:
			parameters.append( bool(self.varAddNoise.get() ))
		except ValueError:
			parameters.append(False)
		try:
			parameters.append( float(self.light_x))
		except ValueError:
			parameters.append(0.0)
		try:
			parameters.append( float(self.light_y))
		except ValueError:
			parameters.append(0.0)
		try:
			parameters.append( bool(self.startFlag ))
		except ValueError:
			parameters.append(False)
		try:
			parameters.append( int(self.entryBehavior.get() ))
		except ValueError:
			parameters.append(-1)
		try:
			parameters.append( int(self.entrySteps.get()))
		except ValueError:
			parameters.append(0)

		return parameters

	def print_graph(self,*args):
			flagOnce=True;

			self.w.delete(self.nodes_image)	
			nodes_coords = []
			image = Image.new('RGBA', (self.canvasX, self.canvasY))
			draw = ImageDraw.Draw(image)
			map_file = open('../data/'+self.entryFile.get()+'/'+self.entryFile.get()+'.top','r')                  #Open file
			lines = map_file.readlines()                          #Split the file in lines
			for line in lines: 									  #To read line by line
				words = line.split()	                          #To separate  words 
				if words:										  #To avoid empty lines							
					if words[0] == "(":							  #To avoid coments
						if words[1] == "num":			  #To get world dimensions
							numNode = float (words[3])	
						elif words[1] == "node":				  #to get polygons vertex
							numNode = words[2]
				#			print(self.graph_list)
							#if int(numNode) in self.graph_list:
							nodeXm = float (words[3]) * self.canvasX / self.mapX
							nodeYm = self.canvasY - ( float (words[4]) * self.canvasY) / self.mapY
								#if flagOnce:
								#	c1 = nodeXm
								#	c2 = nodeYm
								#	flagOnce = False
							nodes_coords.append([nodeXm,nodeYm,numNode])
								#draw.ellipse((nodeXm - 3 ,nodeYm - 3 ,nodeXm + 3 ,nodeYm + 3), outline = '#9C4FDB', fill = '#9C4FDB')
								#draw.text( (nodeXm,nodeYm + 2) ,fill = "darkblue" ,text = str(numNode) )
						#( connection 0 1 0.121195 )
								#draw.line( (c1,c2,nodeXm,nodeYm), fill = '#9C4FDB')
								#c1 = nodeXm
								#c2 = nodeYm
			for x in self.graph_list:
				if x != -1:
					if flagOnce:
						c1 = nodes_coords[x][0]
						c2 = nodes_coords[x][1]
						flagOnce = False
								
					draw.ellipse((nodes_coords[x][0] - 3 ,nodes_coords[x][1] - 3 ,nodes_coords[x][0] + 3 ,nodes_coords[x][1] + 3), outline = '#9C4FDB', fill = '#9C4FDB')
					draw.text( (nodes_coords[x][0],nodes_coords[x][1] + 2) ,fill = "darkblue" ,text = str(nodes_coords[x][2]) )
						#( connection 0 1 0.121195 )
					draw.line( (c1,c2,nodes_coords[x][0],nodes_coords[x][1]), fill = '#9C4FDB')
					c1 = nodes_coords[x][0]
					c2 = nodes_coords[x][1]


			map_file.close()
			image.save('nodes.png')
			self.gif1 = PhotoImage( file = 'nodes.png')
			self.nodes_image = self.w.create_image(self.canvasX / 2, self.canvasY / 2, image = self.gif1)


	def print_nodes(self):

		if not self.varShowNodes.get() :
			self.w.delete(self.nodes_image)	
			self.nodes=None
		else:
			self.w.delete(self.nodes_image)	
			nodes_coords = []
			image = Image.new('RGBA', (self.canvasX, self.canvasY))
			draw = ImageDraw.Draw(image)
			map_file = open('../data/'+self.entryFile.get()+'/'+self.entryFile.get()+'.top','r')                  #Open file
			lines = map_file.readlines()                          #Split the file in lines
			for line in lines: 									  #To read line by line
				words = line.split()	                          #To separate  words 
				if words:										  #To avoid empty lines							
					if words[0] == "(":							  #To avoid coments
						if words[1] == "num":			  #To get world dimensions
							numNode = float (words[3])	
						elif words[1] == "node":				  #to get polygons vertex
							numNode = words[2]
							nodeXm = float (words[3]) * self.canvasX / self.mapX
							nodeYm = self.canvasY - ( float (words[4]) * self.canvasY) / self.mapY
							nodes_coords.append([nodeXm,nodeYm])
							draw.ellipse((nodeXm - 3 ,nodeYm - 3 ,nodeXm + 3 ,nodeYm + 3), outline = '#9C4FDB', fill = '#9C4FDB')
							draw.text( (nodeXm,nodeYm + 2) ,fill = "darkblue" ,text = str(numNode) )
						elif words[1] == "connection":				  #to get polygons vertex
							c1 = int(words[2])
							c2 = int(words[3])
							draw.line( (nodes_coords[c1][0],nodes_coords[c1][1] ,nodes_coords[c2][0] ,nodes_coords[c2][1] ) , fill = '#9C4FDB')
							
			map_file.close()
			image.save('nodes.png')
			self.gif1 = PhotoImage( file = 'nodes.png')
			self.nodes_image = self.w.create_image(self.canvasX / 2, self.canvasY / 2, image = self.gif1)


	def read_map(self):
		#pp=0
		for polygon in self.polygonMap :
			self.w.delete(polygon)
		self.polygonMap = []	
		try:
			#self.w.delete("all")
			map_file = open('../data/'+self.entryFile.get()+'/'+self.entryFile.get()+'.wrl','r') #Open file
			lines = map_file.readlines()                          #Split the file in lines
			for line in lines: 									  #To read line by line
				words = line.split()	                          #To separate  words 
				if words:										  #To avoid empty lines							
					if words[0] == "(":							  #To avoid coments
						if words[1] == "dimensions":			  #To get world dimensions
							self.mapX = float (words[3])	
							self.mapY = float (words[4])
							self.print_grid()
						elif words[1] == "polygon":				  #to get polygons vertex
							vertex_x = [ ( ( self.canvasX * float(x) ) / self.mapX ) for x in words[4:len(words)-1:2]	]
							vertex_y = [ ( self.canvasY -  ( self.canvasY * float(y) ) / self.mapY ) for y in words[5:len(words)-1:2]	]
							vertexs = (zip(vertex_x, vertex_y))
							self.polygonMap.append(self.w.create_polygon(vertexs, outline='#002B7A', fill='#447CFF', width=1))	
							#self.w.create_text( self.canvasX * float(words[4]) / self.mapX,  self.canvasY -  ( self.canvasY * float(words[5]) ) / self.mapY, text=str(pp))
							#pp=pp+1
		except IOError:
			tkMessageBox.showerror("World erros ", "World  '"+self.entryFile.get()+"' doesn' t exist \n Provide another file name ")
	
	def world_change(self,event):
		self.read_map()
		self.print_nodes()

	def behavioLess(self):
		try:
			newbehavior=int(self.entryBehavior.get())
			self.entryBehavior.delete ( 0, END )
			self.entryBehavior.insert ( 0, str(newbehavior-1) )
		except ValueError:
			self.entryBehavior.delete ( 0, END )
			self.entryBehavior.insert ( 0, '1' )
	
	def behavioMore(self):
		try:
			newbehavior=int(self.entryBehavior.get())
			self.entryBehavior.delete ( 0, END )
			self.entryBehavior.insert ( 0, str(newbehavior+1) )
		except ValueError:
			self.entryBehavior.delete ( 0, END )
			self.entryBehavior.insert ( 0, '1' )


	def s_t_simulation(self,star_stop):
		if star_stop :
			state = 'disabled'
			self.read_map()
			self.startFlag=True
			self.steps_ = 0 ;
			self.steps_aux = int(self.entrySteps.get()) ;
			self.entrySteps.delete ( 0, END )
			self.entrySteps.insert ( 0, str(0)  )
		else: 
			state = 'normal'
			self.startFlag=False
			self.entrySteps.delete ( 0, END )
			self.entrySteps.insert ( 0, str(self.steps_aux)  )

		self.entryFile          .configure(state=state)     
		#self.entrySteps         .configure(state=state) 
		self.buttonBehaviorLess .configure(state=state)         
		self.entryBehavior    	.configure(state=state)        
		self.buttonBehaviorMore .configure(state=state)       
		self.checkShowPath      .configure(state=state)  
		self.checkShowSensors   .configure(state=state)  
		self.checkAddNoise      .configure(state=state)    
		self.checkShowNodes     .configure(state=state)             
		self.entryRobot         .configure(state=state)   
		#self.entryPoseX         .configure(state=state)   
		#self.entryPoseY         .configure(state=state)   
		#self.entryAngle         .configure(state=state)   
		self.entryRadio         .configure(state=state)   
		self.entryAdvance       .configure(state=state)   
		self.entryTurnAngle     .configure(state=state)   
		self.entryNumSensors    .configure(state=state)    
		self.entryOrigin        .configure(state=state)    
		self.entryRange         .configure(state=state)    
		self.entryValue         .configure(state=state)


		#self.buttonShowNodes     
		#self.buttonRunSimulation  
		#self.buttonStop        


	def right_click(self,event):
		if self.light >0:
			self.w.delete(self.light)
		self.light = self.w.create_image(event.x, event.y, image = self.gif2)
		self.light_x = self.mapX*event.x / self.canvasX
		self.light_y = self.mapY -  ( self.mapY * event.y ) / self.canvasY
		self.entryLightX.config(text=str(self.light_x)[:4])
		self.entryLightY.config(text=str(self.light_y)[:4])
		#tkMessageBox.showinfo("New light position ", "                 \nx :"+str(self.light_x)+"\n y :"+str(self.light_y)+"")
	


	def left_click(self,event):
		if self.robot > 0:
			self.delete_robot()
		self.robotX = event.x
		self.robotY = event.y
		self.plot_robot()	
		
	
	def gui_init(self):

		self.backgroundColor = '#E9E9EA';#"#FCFCFC";
		self.entrybackgroudColor = "#0063CC";##1A3A6D";
		self.entryforegroundColor = 'white';
		
		self.root = Tk()
		self.root.protocol("WM_DELETE_WINDOW", self.kill)
		self.root.title("Mobile Robot Simulator")
		self.content   = Frame(self.root)
		self.frame     = Frame(self.content,borderwidth = 5, relief = "flat", width = 600, height = 900 ,background = self.backgroundColor)
		self.rightMenu = Frame(self.content,borderwidth = 5, relief = "flat", width = 300, height = 900 ,background = self.backgroundColor)
		self.w = Canvas(self.frame, width = self.canvasX, height = self.canvasY, bg="#FFFFFF")
		self.w.pack()
		
		self.headLineFont = Font( family = 'Helvetica' ,size = 12, weight = 'bold')
		self.lineFont     = Font( family = 'Helvetica' ,size = 10, weight = 'bold')

		self.lableEnvironment   = Label(self.rightMenu ,text = "Environment"     ,background = self.backgroundColor ,foreground = "#303133" ,font = self.headLineFont)
		self.labelFile          = Label(self.rightMenu ,text = "File:"           ,background = self.backgroundColor ,font = self.lineFont)
		self.labelSteps         = Label(self.rightMenu ,text = "Steps:"          ,background = self.backgroundColor ,font = self.lineFont)
		self.labelBehavior		= Label(self.rightMenu ,text = "Behavior:"          ,background = self.backgroundColor ,font = self.lineFont)
		self.labelLightX        = Label(self.rightMenu ,text = "Light X:"          ,background = self.backgroundColor ,font = self.lineFont)
		self.labelLightY        = Label(self.rightMenu ,text = "Light Y:"          ,background = self.backgroundColor ,font = self.lineFont)
		self.labelConfiguration = Label(self.rightMenu ,text = "Configurations:" ,background = self.backgroundColor ,font = self.lineFont)
			
		self.entryFile  = Entry(self.rightMenu ,width = 15 ,foreground = self.entryforegroundColor ,background = self.entrybackgroudColor )
		self.entryFile.bind('<Return>', self.world_change)
		self.entrySteps = Entry(self.rightMenu ,width = 15 ,foreground = self.entryforegroundColor ,background = self.entrybackgroudColor )

		self.buttonBehaviorLess          = Button(self.rightMenu ,width = 1, text = "<" ,command = self.behavioLess)
		self.entryBehavior    	         = Entry(self.rightMenu ,width = 4 ,foreground = self.entryforegroundColor ,background = self.entrybackgroudColor ,justify='center' )
		self.buttonBehaviorMore          = Button(self.rightMenu ,width = 1, text = ">" ,command = self.behavioMore)
		
		self.entryLightX = Label(self.rightMenu ,text = "Click Right" ,background = self.backgroundColor ,font = self.lineFont ,justify='center')
		self.entryLightY = Label(self.rightMenu ,text = "Click Right" ,background = self.backgroundColor ,font = self.lineFont ,justify='center')

		self.entryFile.insert ( 0, 'random_2' )
		self.entrySteps.insert( 0, '100' )
		self.entryBehavior.insert ( 0, '1' )

		##### Rigth menu widgets declaration

		# Environment

		self.varShowPath    = IntVar()
		self.varShowSensors = IntVar()
		self.varAddNoise    = IntVar()
		self.varShowNodes   = IntVar()

		self.checkShowPath    = Checkbutton(self.rightMenu ,text = 'Show path'    ,variable = self.varShowPath    ,onvalue = 1 ,offvalue = 0 ,background = self.backgroundColor)
		self.checkShowSensors = Checkbutton(self.rightMenu ,text = 'Show Sensors' ,variable = self.varShowSensors ,onvalue = 1 ,offvalue = 0 ,background = self.backgroundColor)
		self.checkAddNoise    = Checkbutton(self.rightMenu ,text = 'Add Noise'    ,variable = self.varAddNoise    ,onvalue = 1 ,offvalue = 0 ,background = self.backgroundColor)
		self.checkShowNodes   = Checkbutton(self.rightMenu ,text = 'Show Nodes'    ,variable = self.varShowNodes  ,onvalue = 1 ,offvalue = 0 ,background = self.backgroundColor ,command=self.print_nodes)

		self.checkShowPath    .deselect()
		self.checkShowSensors .deselect()
		self.checkAddNoise    .deselect()
		self.checkShowNodes   .deselect()
		# Robot 

		self.lableRobot     = Label(self.rightMenu ,text = "Robot"              ,background = self.backgroundColor ,foreground = "#303133" ,font = self.headLineFont )
		self.labelPoseX     = Label(self.rightMenu ,text = "Pose X:"            ,background = self.backgroundColor ,font = self.lineFont)
		self.labelPoseY     = Label(self.rightMenu ,text = "Pose Y:"            ,background = self.backgroundColor ,font = self.lineFont)
		self.labelAngle     = Label(self.rightMenu ,text = "Angle:"             ,background = self.backgroundColor ,font = self.lineFont)
		self.labelRadio     = Label(self.rightMenu ,text = "Radio:"             ,background = self.backgroundColor ,font = self.lineFont)
		self.labelAdvance   = Label(self.rightMenu ,text = "Magnitude Advance:" ,background = self.backgroundColor ,font = self.lineFont)
		self.labelTurnAngle = Label(self.rightMenu ,text = "Turn Angle:"        ,background = self.backgroundColor ,font = self.lineFont)


		self.entryRobot     = Entry(self.rightMenu, width = 8 ,background = self.entrybackgroudColor  ,foreground = self.entryforegroundColor)
		self.entryPoseX     = Entry(self.rightMenu, width = 8 ,background = self.entrybackgroudColor  ,foreground = self.entryforegroundColor)
		self.entryPoseY     = Entry(self.rightMenu, width = 8 ,background = self.entrybackgroudColor  ,foreground = self.entryforegroundColor)
		self.entryAngle     = Entry(self.rightMenu, width = 8 ,background = self.entrybackgroudColor  ,foreground = self.entryforegroundColor)
		self.entryRadio     = Entry(self.rightMenu, width = 8 ,background = self.entrybackgroudColor  ,foreground = self.entryforegroundColor)
		self.entryAdvance   = Entry(self.rightMenu, width = 8 ,background = self.entrybackgroudColor  ,foreground = self.entryforegroundColor)
		self.entryTurnAngle = Entry(self.rightMenu, width = 8 ,background = self.entrybackgroudColor  ,foreground = self.entryforegroundColor)

		self.entryPoseX     .insert ( 0, '0.5' )
		self.entryPoseY     .insert ( 0, '200' )
		self.entryAngle     .insert ( 0, '0.0' )
		self.entryRadio     .insert ( 0, '0.03' )
		self.entryAdvance   .insert ( 0, '0.04' )
		self.entryTurnAngle .insert ( 0, '0.7857' )

		self.labelVelocity = Label(self.rightMenu ,text = "Execution velocity:"        ,background = self.backgroundColor ,font = self.lineFont)
		self.sliderVelocity =Scale(self.rightMenu, from_=1, to=15, orient=HORIZONTAL ,length=300 ,background = self.backgroundColor ,font = self.lineFont)
		

		# Sensors

		self.lableSensors     = Label(self.rightMenu, text = "Sensors"       ,background = self.backgroundColor ,foreground = "#303133" ,font = self.headLineFont)
		self.labelNumSensors  = Label(self.rightMenu, text = "Num Sensors:"  ,background = self.backgroundColor ,font = self.lineFont)
		self.labelOrigin      = Label(self.rightMenu, text = "Origin angle:" ,background = self.backgroundColor ,font = self.lineFont)
		self.labelRange       = Label(self.rightMenu, text = "Range:"        ,background = self.backgroundColor ,font = self.lineFont)
		self.labelValue       = Label(self.rightMenu, text = "Value:"        ,background = self.backgroundColor ,font = self.lineFont)

		self.entryNumSensors = Entry(self.rightMenu, width = 8 ,background = self.entrybackgroudColor ,foreground = self.entryforegroundColor)
		self.entryOrigin     = Entry(self.rightMenu, width = 8 ,background = self.entrybackgroudColor ,foreground = self.entryforegroundColor)
		self.entryRange      = Entry(self.rightMenu, width = 8 ,background = self.entrybackgroudColor ,foreground = self.entryforegroundColor)
		self.entryValue      = Entry(self.rightMenu, width = 8 ,background = self.entrybackgroudColor ,foreground = self.entryforegroundColor)

		self.entryNumSensors   .insert ( 0, '2')
		self.entryOrigin       .insert ( 0, '-1.5707' )
		self.entryRange        .insert ( 0, '3.1415' )
		self.entryValue        .insert ( 0, '0.3' )

		# buttons

		self.lableSimulator      = Label (self.rightMenu ,text = "Simulator" ,background = self.backgroundColor ,foreground = "#303133" ,font = self.headLineFont)
		self.buttonShowNodes     = Button(self.rightMenu ,width = 20, text = "Show Nodes" ,command = lambda: self.move_robot(self.entryPoseX.get(),self.entryPoseY.get()))
		self.buttonRunSimulation = Button(self.rightMenu ,width = 20, text = "Run simulation" ,command = lambda: self.s_t_simulation(True) )
		self.buttonStop          = Button(self.rightMenu ,width = 20, text = "Stop" ,command = lambda: self.s_t_simulation(False) )

		#### Right menu widgets grid			

		# Environment
		self.lableEnvironment  .grid(column = 0 ,row = 0 ,sticky = (N, W) ,padx = (5,5))
		self.labelFile         .grid(column = 0 ,row = 1 ,sticky = (N, W) ,padx = (10,5))
		self.labelSteps        .grid(column = 0 ,row = 2 ,sticky = (N, W) ,padx = (10,5))
		self.labelBehavior     .grid(column = 0 ,row = 3 ,sticky = (N, W) ,padx = (10,5))
		self.labelLightX       .grid(column = 0 ,row = 4 ,sticky = (N, W) ,padx = (10,5))
		self.labelLightY       .grid(column = 0 ,row = 5 ,sticky = (N, W) ,padx = (10,5))

		self.labelConfiguration.grid(column = 0 ,row = 7 ,sticky = (N, W) ,padx = (10,5))

		self.entryFile       .grid(column = 1 ,row = 1 ,columnspan = 2 ,sticky = (N, W) ,padx = 5)
		self.entrySteps		 .grid(column = 1 ,row = 2 ,columnspan = 2 ,sticky = (N, W) ,padx = 5)	
		
		self.buttonBehaviorLess.grid(column = 1 ,row = 3 ,columnspan = 1 ,sticky = (N, W) ,padx = 5)
		self.entryBehavior   .grid(column = 1 ,row = 3 ,columnspan = 1  ,padx = 5)
		self.buttonBehaviorMore.grid(column = 1 ,row = 3 ,columnspan = 1 ,sticky = (N, E) ,padx = 5)
		
		self.entryLightX.grid(column = 1 ,row = 4 ,columnspan = 2 ,sticky = (N, W) ,padx = 5)
		self.entryLightY.grid(column = 1 ,row = 5 ,columnspan = 2 ,sticky = (N, W) ,padx = 5)
		

		self.checkShowPath   .grid(column = 1 ,row = 7  ,sticky = (N, W) ,padx = 5)
		self.checkShowSensors.grid(column = 1 ,row = 8  ,sticky = (N, W) ,padx = 5)
		self.checkAddNoise   .grid(column = 1 ,row = 9  ,sticky = (N, W) ,padx = 5)
		self.checkShowNodes  .grid(column = 1 ,row = 10  ,sticky = (N, W) ,padx = 5) 

		# Robot

		self.lableRobot     .grid(column = 4 ,row = 0 ,sticky = (N, W) ,padx = (5,5))     
		self.labelPoseX     .grid(column = 4 ,row = 1 ,sticky = (N, W) ,padx = (10,5))
		self.labelPoseY     .grid(column = 4 ,row = 2 ,sticky = (N, W) ,padx = (10,5))
		self.labelAngle     .grid(column = 4 ,row = 3 ,sticky = (N, W) ,padx = (10,5))
		self.labelRadio     .grid(column = 4 ,row = 4 ,sticky = (N, W) ,padx = (10,5))
		self.labelAdvance   .grid(column = 4 ,row = 5 ,sticky = (N, W) ,padx = (10,5))
		self.labelTurnAngle .grid(column = 4 ,row = 6 ,sticky = (N, W) ,padx = (10,5))
		self.labelVelocity	.grid(column = 4 ,row = 7 ,sticky = (N, W) ,padx = (10,5))
		
		self.sliderVelocity .grid(column = 4 ,row = 8 ,columnspan = 2 ,rowspan = 2 ,sticky = (N, W), padx = 5)

		self.entryPoseX     .grid(column = 5 ,row = 1 ,columnspan = 2 ,sticky = (N, W), padx = 5)
		self.entryPoseY     .grid(column = 5 ,row = 2 ,columnspan = 2 ,sticky = (N, W), padx = 5)
		self.entryAngle     .grid(column = 5 ,row = 3 ,columnspan = 2 ,sticky = (N, W), padx = 5)
		self.entryRadio     .grid(column = 5 ,row = 4 ,columnspan = 2 ,sticky = (N, W), padx = 5)
		self.entryAdvance   .grid(column = 5 ,row = 5 ,columnspan = 2 ,sticky = (N, W), padx = 5)
		self.entryTurnAngle .grid(column = 5 ,row = 6 ,columnspan = 2 ,sticky = (N, W), padx = 5)
		
		# Sensors

		self.lableSensors       .grid(column = 0 ,row = 11  ,sticky = (N, W) ,padx = (5,5))     
		self.labelNumSensors    .grid(column = 0 ,row = 12  ,sticky = (N, W) ,padx = (10,5))
		self.labelOrigin        .grid(column = 0 ,row = 13  ,sticky = (N, W) ,padx = (10,5))
		self.labelRange         .grid(column = 0 ,row = 14 ,sticky = (N, W) ,padx = (10,5))
		self.labelValue         .grid(column = 0 ,row = 15 ,sticky = (N, W) ,padx = (10,5))

		self.entryNumSensors    .grid(column = 1 ,row = 12  ,columnspan=2 ,sticky = (N, W) ,padx = 5)
		self.entryOrigin        .grid(column = 1 ,row = 13  ,columnspan=2 ,sticky = (N, W) ,padx = 5)
		self.entryRange         .grid(column = 1 ,row = 14 ,columnspan=2 ,sticky = (N, W) ,padx = 5)
		self.entryValue         .grid(column = 1 ,row = 15 ,columnspan=2 ,sticky = (N, W) ,padx = 5)

		# buttons

		self.lableSimulator     .grid(column = 4 ,row = 11  ,sticky = (N, W) ,padx = (5,5))
		self.buttonShowNodes    .grid(column = 4 ,row = 12  ,sticky = (N, W) ,padx = (10,5))
		self.buttonRunSimulation.grid(column = 4 ,row = 13 ,sticky = (N, W) ,padx = (10,5))
		self.buttonStop         .grid(column = 4 ,row = 14 ,sticky = (N, W) ,padx = (10,5))

		self.content  .grid(column = 0 ,row = 0 ,sticky = (N, S, E, W))
		self.frame    .grid(column = 0 ,row = 0 ,columnspan = 3 ,rowspan = 2 ,sticky = (N, S, E, W))
		self.rightMenu.grid(column = 3 ,row = 0 ,columnspan = 3 ,rowspan = 2 ,sticky = (N, S, E, W))

		self.root.columnconfigure(0, weight=1)
		self.root.rowconfigure(0, weight=1)
		self.content.columnconfigure(0, weight = 3)
		self.content.columnconfigure(1, weight = 3)
		self.content.columnconfigure(2, weight = 3)
		self.content.columnconfigure(3, weight = 1)
		self.content.columnconfigure(4, weight = 1)
		self.content.rowconfigure(1, weight = 1)

		self.gif2 = PhotoImage( file = 'light.png')
		self.gif2.zoom(50, 50)

		self.a = IntVar(value=3)
		self.a.trace("w", self.move_robot)
		
		self.b = IntVar(value=3)
		self.b.trace("w", self.print_graph)

		self.w.bind("<Button-3>", self.right_click)
		self.w.bind("<Button-1>", self.left_click)


	def print_grid(self):
		for i in range(0, int(self.mapX)*10):
			self.w.create_line( i * self.canvasX/(self.mapX*10),0, i*self.canvasX/(self.mapX*10), self.canvasY,  dash=(4, 4), fill="#D1D2D4")
		for i in range(0, int(self.mapY)*10):
			self.w.create_line( 0, i*self.canvasY/(self.mapY*10),self.canvasX, i*self.canvasY/(self.mapY*10),   dash=(4, 4), fill="#D1D2D4")
	
	def rotate_point(self,theta,ox,oy, x, y):
		rotate = -theta
		nx = ( x - ox ) * math.cos( rotate ) - ( y - oy ) * math.sin(rotate) + ox
		ny = ( x - ox ) * math.sin( rotate ) + ( y - oy ) * math.cos(rotate) + oy
		return nx,ny

	def plot_robot(self):
		
		x = self.robotX
		y = self.robotY
		angle=self.robotAngle

		try:
			self.entryPoseX.delete ( 0, END )
			self.entryPoseY.delete ( 0, END )
			self.entryAngle.delete ( 0, END )
			self.entryPoseX.insert ( 0, str(float(x)*self.mapX / self.canvasX) )
			self.entryPoseY.insert ( 0, str(self.mapY  - (float(y)*self.mapX / self.canvasY )  )) 
			self.entryAngle.insert ( 0, str(angle) ) 

		except ValueError:
			pass


		if self.flagOnce :
			self.delete_robot()
		self.flagOnce=True

		radio = ( float(self.entryRadio.get() ) * self.canvasX ) / self.mapX
		self.robot=self.w.create_oval(x-radio,y-radio, x+radio,y+radio   , outline='#F7CE3F', fill='#F7CE3F', width=1)
		self.hokuyo=self.w.create_oval(x-radio/5,y-radio/5, x+radio/5,y+radio/5 ,outline='#4F58DB', fill='#4F58DB', width=1)
		
		wheel1x1 = x - ( radio / 2 )
		wheel1y1 = y - ( 5 * radio /6 )
		wheel1x2 = x + radio / 2
		wheel1y2 = y - ( 3 * radio / 6 )
		wheel2y1 = y + ( 3 * radio / 6 )
		wheel2y2 = y + ( 5 * radio / 6 )
		wh1= []
		wh2= []
		wh1.append(self.rotate_point (angle ,x ,y ,wheel1x1 ,wheel1y1))
		wh1.append(self.rotate_point (angle ,x ,y ,wheel1x2 ,wheel1y1))
		wh1.append(self.rotate_point (angle ,x ,y ,wheel1x2 ,wheel1y2))
		wh1.append(self.rotate_point (angle ,x ,y ,wheel1x1 ,wheel1y2))
		wh2.append(self.rotate_point (angle ,x ,y ,wheel1x1 ,wheel2y1))
		wh2.append(self.rotate_point (angle ,x ,y ,wheel1x2 ,wheel2y1))
		wh2.append(self.rotate_point (angle ,x ,y ,wheel1x2 ,wheel2y2))
		wh2.append(self.rotate_point (angle ,x ,y ,wheel1x1 ,wheel2y2))
		self.wheelL=self.w.create_polygon( wh1 ,outline = '#404000', fill = '#404000', width=1)
		self.wheelR=self.w.create_polygon( wh2 ,outline = '#404000', fill = '#404000', width=1)
		head = []
		head.append( self.rotate_point( angle ,x ,y ,x + ( 2 * radio / 3 ) ,y - ( radio / 3 ) ) )
		head.append( self.rotate_point( angle ,x ,y ,x + ( 2 * radio / 3 ) ,y + ( radio / 3 ) ) )
		head.append( self.rotate_point( angle ,x ,y ,x + ( 5 * radio / 6 ) ,y ))
		self.arrow=self.w.create_polygon( head , outline = '#1AAB4A' ,fill = '#1AAB4A', width = 1 )
		self.w.update()
		if self.varShowSensors.get():
			self.plot_sensors(angle,x,y)
		else:
			for i in self.lasers:
				self.w.delete(i)
			self.lasers = []
		

	def get_ray(self,angle,x,y,r):

		return r * math.cos( angle ) + x ,r * ( - math.sin(angle) ) + y


	def plot_sensors(self,angle,rx,ry):
		
		originSensor = float( self.entryOrigin.get())   # -1.5707
		rangeSensor  = float( self.entryRange.get() )    #  240#3.1415
		numSensor    = int(self.entryNumSensors.get())
		#angle=math.radians(math.degrees(angle))
		x =  ( float( self.entryValue.get() ) * self.canvasX ) / self.mapY
		
		y = ry
		
		f = angle + originSensor
		step = float( float( rangeSensor ) / float( numSensor - 1 ) )

		for i in self.lasers:
			self.w.delete(i)
		self.lasers = []
		for i in range(0, numSensor):	
			q,w =self.get_ray(f ,rx ,ry ,(self.sensors_value[i]  * self.canvasX ) / self.mapY)
			self.lasers.append(self.w.create_line(rx ,ry ,q ,w ,fill = "#00DD41") )
			f = f + step

		#if self.flagF :
		#	
		#	for x in self.lasers:
		#		self.w.delete(x)
		#	self.lasers = []
		#	for i in range(0, numSensor):	
		#		q,w =self.get_ray(f ,rx ,ry ,x)
		#		self.lasers.append(self.w.create_line(rx ,ry ,q ,w ,fill = "#00DD41") )
		#		f = f + step
		#	#self.flagF=False
		#else:
		#	for i in range(0, numSensor):	
		#		q,w =self.get_ray(f ,rx ,ry ,x)
		#		self.w.coords(self.lasers[i],rx ,ry,q,w )
		#		f = f + step
		#		#print "line "+str(rx)+" "+str(ry)+" "+str(self.get_ray(f ,rx ,ry ,x))
		#	self.w.update()

		
	def delete_robot(self):
		
		self.w.delete(self.robot)
		self.w.delete(self.wheelL)
		self.w.delete(self.wheelR)
		self.w.delete(self.arrow)
		self.w.delete(self.hokuyo)
		
	def move_robot(self,*args):

		theta = float(self.p_giro)
		distance = float(self.p_distance) 
		
		init_robotX = self.robotX
		init_robotY = self.robotY
		init_robotAngle = self.robotAngle
		i = self.robotAngle

		if theta ==0:
			pass
		else:
			if theta > 0 :
				while i < init_robotAngle + theta:
					i = i + 0.0174533*self.sliderVelocity.get()
					self.robotAngle = i
					self.plot_robot()
					
			else:
				while i > init_robotAngle + theta:
					i = i - 0.0174533*self.sliderVelocity.get()
					self.robotAngle = i
					self.plot_robot()
					
			self.robotAngle = init_robotAngle + theta
			self.plot_robot()

		xf = distance * math.cos(self.robotAngle) + self.robotX
		#print(init_robotX)
		#print(xf)
		yf = -( distance * math.sin(self.robotAngle) )+ self.robotY
		#print(yf)

		x = auxX = init_robotX
		y = auxY = init_robotY
		m = -math.tan(self.robotAngle)

		if xf==auxX :
			if yf <= auxY:
				while y < yf:
					y = y - self.sliderVelocity.get()
					self.robotY=y
					self.plot_robot()
			else:
				while y > yf:
					y = y + self.sliderVelocity.get()
					self.robotY=y
					self.plot_robot()
			self.robotY = yf
			self.plot_robot()
		else:    # Calculos con punto pendiente  y2 -y1= m ( x2 - x1)
			if  m < -1 or  m > 1 : # Si los angulos caen en este rango en vez de evaluar y  evaluaremos x

				if yf > auxY:
					while y < yf:
						x = -( (y - auxY) / math.tan(self.robotAngle) -auxX	)
						y = y + self.sliderVelocity.get()
						self.robotX=x
						self.robotY=y
						self.plot_robot()	
				else:
					while y > yf:
						x = -( (y - auxY) / math.tan(self.robotAngle) -auxX)   
						y = y - self.sliderVelocity.get()
						self.robotX=x
						self.robotY=y
						self.plot_robot()	
			else:

				if xf > auxX:
					while x < xf:
						y = -math.tan(self.robotAngle) * (x - auxX) + auxY
						#print(y)
						x = x + self.sliderVelocity.get()
						self.robotX=x
						self.robotY=y
						self.plot_robot()	
				else:
					while x > xf:
						y = -math.tan(self.robotAngle) * (x - auxX) + auxY
						x = x - self.sliderVelocity.get()
						self.robotX=x
						self.robotY=y
						self.plot_robot()	
				
					
			self.robotX = xf
			self.robotY = yf
			self.plot_robot()



	def handle_service(self,theta,distance):
		self.p_giro = theta
		self.p_distance = distance * self.canvasX 
		
		
		self.steps_= self.steps_+1;

		self.entrySteps.delete ( 0, END )
		self.entrySteps.insert ( 0, str(self.steps_)  )

		if self.steps_ == self.steps_aux:
			self.s_t_simulation(False);

		self.a.set(1)

	def handle_print_graph(self,graph_list):
		self.graph_list = graph_list 
		self.b.set(1)
		
	def run(self):	
		self.gui_init()
		self.read_map()
		
		#self.w.create_rectangle(0.010000* self.canvasX, (self.canvasY-( 0.990000* self.canvasY )) ,  (0.000000* self.canvasX), (self.canvasY-(0.000000* self.canvasX)), outline='#000000', width=1)
		#self.w.create_rectangle(1.000000* self.canvasX, (self.canvasY-( 1.000000* self.canvasY )) ,  (0.000000* self.canvasX), (self.canvasY-(0.990000* self.canvasX)), outline='#000000', width=1)
		#self.w.create_rectangle(1.000000* self.canvasX, (self.canvasY-( 1.000000* self.canvasY )) ,  (0.990000* self.canvasX), (self.canvasY-(0.000000* self.canvasX)), outline='#000000', width=1)
		#self.w.create_rectangle(1.000000* self.canvasX, (self.canvasY-( 0.010000* self.canvasY )) ,  (0.000000* self.canvasX), (self.canvasY-(0.000000* self.canvasX)), outline='#000000', width=1)
		#self.w.create_rectangle(0.771493* self.canvasX, (self.canvasY-( 0.821316* self.canvasY )) ,  (0.645470* self.canvasX), (self.canvasY-(0.713081* self.canvasX)), outline='#000000', width=1)
		#self.w.create_rectangle(0.500906* self.canvasX, (self.canvasY-( 0.411829* self.canvasY )) ,  (0.390196* self.canvasX), (self.canvasY-(0.269637* self.canvasX)), outline='#000000', width=1)
		#self.w.create_rectangle(0.915681* self.canvasX, (self.canvasY-( 0.227208* self.canvasY )) ,  (0.781156* self.canvasX), (self.canvasY-(0.136487* self.canvasX)), outline='#000000', width=1)
		#self.w.create_rectangle(0.383984* self.canvasX, (self.canvasY-( 0.776612* self.canvasY )) ,  (0.256041* self.canvasX), (self.canvasY-(0.663362* self.canvasX)), outline='#000000', width=1)
		#self.w.create_rectangle(0.248994* self.canvasX, (self.canvasY-( 0.320795* self.canvasY )) ,  (0.137446* self.canvasX), (self.canvasY-(0.219173* self.canvasX)), outline='#000000', width=1)
		#self.w.create_rectangle(0.209660* self.canvasX, (self.canvasY-( 0.631059* self.canvasY )) ,  (0.116433* self.canvasX), (self.canvasY-(0.490052* self.canvasX)), outline='#000000', width=1)
		#self.w.create_rectangle(0.795078* self.canvasX, (self.canvasY-( 0.588163* self.canvasY )) ,  (0.671304* self.canvasX), (self.canvasY-(0.493697* self.canvasX)), outline='#000000', width=1)
		#self.w.create_rectangle(0.538616* self.canvasX, (self.canvasY-( 0.880417* self.canvasY )) ,  (0.452314* self.canvasX), (self.canvasY-(0.758960* self.canvasX)), outline='#000000', width=1)
		#self.w.create_rectangle(0.650005* self.canvasX, (self.canvasY-( 0.228883* self.canvasY )) ,  (0.527580* self.canvasX), (self.canvasY-(0.109133* self.canvasX)), outline='#000000', width=1)
		#self.w.create_rectangle(0.551021* self.canvasX, (self.canvasY-( 0.651132* self.canvasY )) ,  (0.422105* self.canvasX), (self.canvasY-(0.528609* self.canvasX)), outline='#000000', width=1)
		#self.w.create_rectangle(0.430000* self.canvasX, (self.canvasY-( 0.630000* self.canvasY )) ,  (0.350000* self.canvasX), (self.canvasY-(0.550000* self.canvasX)), outline='#000000', width=1)
		#self.w.create_oval(0.430000* self.canvasX, (self.canvasY-( 0.630000* self.canvasY )) ,  (0.350000* self.canvasX), (self.canvasY-(0.550000* self.canvasX)), outline='#000000', width=1)
		
		self.root.mainloop()