#include <gl/glut.h>   
#include <Windows.h>  

static GLfloat angle = 0.0f;
void myDisplay(void)
{
	glClearColor(0.0, 0.0, 0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //清理颜色和深度缓存       


														 // 创建透视效果视图        
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0f, 1.0f, 1.0f, 20.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 12.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// 定义太阳光源，它是一种白色的光源     
	{
		//光源的位置在世界坐标系右上角
		GLfloat sun_light_position[] = { 0.0f, 1.0f, 0.6f, 0.0f };
		GLfloat sun_light_ambient[] = { 0.0f, 0.0f, 0.0f, 0.0f }; //RGBA模式的环境光，为0  
		GLfloat sun_light_diffuse[] = { 0.3f, 0.3f, 0.3f, 0.0f }; //RGBA模式的漫反射光，全白光 

		GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 0.0f };  //RGBA模式下的镜面光 ，全白光  
		glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);

		//开启灯光  
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);
	}

	// 定义球体的材质并绘制地球      
	{
		//蓝球
		//GLfloat earth_mat_ambient[] = { 0.0f, 0.0f, 1.0f, 1.0f };  //定义材质的环境光颜色，骗蓝色  
		GLfloat earth_mat_diffuse[] = { 0.0f, 0.0f, 1.0f, 1.0f };  //定义材质的漫反射光颜色，偏蓝色  
		GLfloat earth_mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };   //定义材质的镜面反射光颜色，白色  
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };   //定义材质的辐射光颜色，为0  
		GLfloat earth_mat_shininess = 30.0f;
		//glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);
		glTranslatef(7.0f, 0.0f, 0.0f);
		//3.0是半径
		glutSolidSphere(3.4, 40, 60);
	}
	{
		//绿球
		//GLfloat earth_mat_ambient[] = { 0.0f, 1.0f, 0.0f, 0.0f };  //定义材质的环境光颜色，骗蓝色  
		GLfloat earth_mat_diffuse[] = { 0.0f, 1.0f, 0.0f, 1.0f };  //定义材质的漫反射光颜色，偏蓝色  
		GLfloat earth_mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };   //定义材质的镜面反射光颜色，白色  
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };   //定义材质的辐射光颜色，为0  
		GLfloat earth_mat_shininess = 30.0f;
		//glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);
		glTranslatef(-6.0f, 0.0f, 0.0f);
		glutSolidSphere(2.0, 40, 60);
	}
	{
		//红球
		//GLfloat earth_mat_ambient[] = { 1.0f, 0.0f, 0.0f, 1.0f };  //定义材质的环境光颜色，骗蓝色  
		GLfloat earth_mat_diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };  //定义材质的漫反射光颜色，偏蓝色  
		GLfloat earth_mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };   //定义材质的镜面反射光颜色，白色  
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };   //定义材质的辐射光颜色，为0  
		GLfloat earth_mat_shininess = 30.0f;
		//glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);
		glTranslatef(-4.0f, 0.0f, 0.0f);
		glutSolidSphere(2.0, 40, 60);
	}
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(400, 400);
	glutCreateWindow("OpenGL光照演示");
	glutDisplayFunc(&myDisplay);
	glutMainLoop();
	return 0;
}