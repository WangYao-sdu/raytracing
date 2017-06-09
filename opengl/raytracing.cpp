#include <gl/glut.h>   
#include <Windows.h>  

static GLfloat angle = 0.0f;
void myDisplay(void)
{
	glClearColor(0.0, 0.0, 0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //������ɫ����Ȼ���       


														 // ����͸��Ч����ͼ        
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0f, 1.0f, 1.0f, 20.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 12.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// ����̫����Դ������һ�ְ�ɫ�Ĺ�Դ     
	{
		//��Դ��λ������������ϵ���Ͻ�
		GLfloat sun_light_position[] = { 0.0f, 1.0f, 0.6f, 0.0f };
		GLfloat sun_light_ambient[] = { 0.0f, 0.0f, 0.0f, 0.0f }; //RGBAģʽ�Ļ����⣬Ϊ0  
		GLfloat sun_light_diffuse[] = { 0.3f, 0.3f, 0.3f, 0.0f }; //RGBAģʽ��������⣬ȫ�׹� 

		GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 0.0f };  //RGBAģʽ�µľ���� ��ȫ�׹�  
		glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);

		//�����ƹ�  
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);
	}

	// ��������Ĳ��ʲ����Ƶ���      
	{
		//����
		//GLfloat earth_mat_ambient[] = { 0.0f, 0.0f, 1.0f, 1.0f };  //������ʵĻ�������ɫ��ƭ��ɫ  
		GLfloat earth_mat_diffuse[] = { 0.0f, 0.0f, 1.0f, 1.0f };  //������ʵ����������ɫ��ƫ��ɫ  
		GLfloat earth_mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };   //������ʵľ��淴�����ɫ����ɫ  
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };   //������ʵķ������ɫ��Ϊ0  
		GLfloat earth_mat_shininess = 30.0f;
		//glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);
		glTranslatef(7.0f, 0.0f, 0.0f);
		//3.0�ǰ뾶
		glutSolidSphere(3.4, 40, 60);
	}
	{
		//����
		//GLfloat earth_mat_ambient[] = { 0.0f, 1.0f, 0.0f, 0.0f };  //������ʵĻ�������ɫ��ƭ��ɫ  
		GLfloat earth_mat_diffuse[] = { 0.0f, 1.0f, 0.0f, 1.0f };  //������ʵ����������ɫ��ƫ��ɫ  
		GLfloat earth_mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };   //������ʵľ��淴�����ɫ����ɫ  
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };   //������ʵķ������ɫ��Ϊ0  
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
		//����
		//GLfloat earth_mat_ambient[] = { 1.0f, 0.0f, 0.0f, 1.0f };  //������ʵĻ�������ɫ��ƭ��ɫ  
		GLfloat earth_mat_diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };  //������ʵ����������ɫ��ƫ��ɫ  
		GLfloat earth_mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };   //������ʵľ��淴�����ɫ����ɫ  
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };   //������ʵķ������ɫ��Ϊ0  
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
	glutCreateWindow("OpenGL������ʾ");
	glutDisplayFunc(&myDisplay);
	glutMainLoop();
	return 0;
}