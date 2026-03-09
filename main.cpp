#include<iostream>
//#include <unistd.h>
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
using namespace std;
static int right_shoulder_z = 0,left_shoulder_z=0,right_shoulder_y=0,left_shoulder_y=0, left_elbow=0,right_elbow=0,neck=0;
static int left_first_finger=-10,left_second_finger=10,right_first_finger=10,right_second_finger=-10,all_on_y=0;
static float whole_robot=-6.0,axis=-3.0,iris1=0.81,iris2=0.82,iris3=0.26;
static int view_angle=0,tier_angle=0;
static float xpos=0.0,zpos=0.0;
static float left_hand_angle=0.0,right_hand_angle=0.0,teapot_trans=0.0;
bool dancing=false,dance_1_bool,dance_2_bool,dance_4_bool,left_hand_bool,shock_absorber_bool=false;
void init(void)
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glShadeModel(GL_SMOOTH);
}
void animation1(void){
    if(right_elbow>=-150&&left_elbow<=150&&dance_1_bool==false)
          {
              right_elbow-=(1);
              left_elbow+=(1);
              neck++;
              cout<<neck<<endl;
              glutPostRedisplay();
                if(right_elbow==-150){
                    dance_1_bool=true;
                    /*shock_absorber_bool=true;
                    axis+=0.8;
                    whole_robot-=0.8;*/}

          }
     else if(right_elbow<=-30&left_elbow>=30&&dance_1_bool==true){
                right_elbow+=(1);
                left_elbow-=(1);
                glutPostRedisplay();
                neck--;
                if(right_elbow==-30){
                    dance_1_bool=false;
                    /*shock_absorber+=0.18;
                    axis-=0.8;
                    whole_robot+=0.8;*/}
     }

     else{
            glutIdleFunc(NULL);
        }
}
void animation2(void){
    if(right_shoulder_z>-90&&left_shoulder_z<90&&dance_2_bool==false)
          {
              right_shoulder_z-=(1);
              left_shoulder_z+=(1);
              cout<<left_shoulder_z<<endl;
              glutPostRedisplay();
                if(right_shoulder_z==-90){
                    dance_2_bool=true;
                    cout<<"dance bool"<<dance_2_bool<<endl;
                    shock_absorber_bool=true,axis+=0.8,whole_robot-=0.8;
                    iris1=0.0,iris2=0.0,iris3=1.0;}

          }
     else if(right_shoulder_z<=0&left_shoulder_z>=0&&dance_2_bool==true){
                right_shoulder_z+=(1);
                left_shoulder_z-=(1);
                cout<<left_shoulder_z<<endl;
                glutPostRedisplay();
                if(right_shoulder_z==0){
                    dance_2_bool=false;
                    cout<<"dance bool"<<dance_2_bool<<endl;
                    shock_absorber_bool=false,axis-=0.8,whole_robot+=0.8;
                     iris1=0.0,iris2=1.0,iris3=0.0;}
     }

     else{
            glutIdleFunc(NULL);
        }

}
void animation3(void){
    if(left_hand_angle<=50.0&&left_hand_bool==false){
            left_hand_angle+=0.2;
            cout<<left_hand_angle<<endl;
            glutPostRedisplay();
            if(int(left_hand_angle)==50){
                left_hand_bool=true;
                cout<<"true"<<endl;}}
     else if(left_hand_angle>=0.0&&left_hand_bool==true){
            left_hand_angle-=0.5;
            glutPostRedisplay();
            if(int(left_hand_angle)==0){
                    glutIdleFunc(NULL),dancing=false;
                    teapot_trans=0.0,left_first_finger=-10,left_second_finger=10,left_shoulder_z=0.0,left_shoulder_y=0.0,left_elbow=0.0;
                    shock_absorber_bool=false,whole_robot=-6.0,axis=-3.0;

                    cout<<"glut Idlefunc NULL"<<endl;}


     }




}
void animation4(void){
    if(left_elbow>=-80&&dance_4_bool==false)
    {
        left_elbow-=1;
        glutPostRedisplay();
        if(left_elbow==-80)
            dance_4_bool=true;
    }
    if(left_elbow<=-20&&dance_4_bool==true){
        left_elbow+=1;
        glutPostRedisplay();
        if(left_elbow==-20)
            dance_4_bool=false;
    }
}
void draw_a_door(void){
    GLfloat mat_diff1[]={1.0, 0.24, 0.15,1.0};
    GLfloat mat_diff2[]={0.90, 0.70, 0.53,1.0};
    //door body
    glPushMatrix();
        glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diff1);
        glColor3f(0.69, 0.46, 0.05);
        glScalef(2.0,5.0,0.05);
        glutSolidCube(1.0);
    glPopMatrix();
    //door handle
    glPushMatrix();
        glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diff2);
        glColor3f(0.90, 0.70, 0.53);
        glTranslatef(0.5,-0.3,.05);
        glutSolidSphere(0.1,100,100);
    glPopMatrix();

}
void draw_a_closet(void){
            GLfloat mat_diff1[]={0.92, 0.81, 0.99,1.0};
            GLfloat mat_diff2[]={0.90, 0.70, 0.53,1.0};
            //closet body
            glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diff1);
            glColor3f(0.92, 0.81, 0.99);
            glPushMatrix();
            glScalef(1.5,4.0,1.0);
            glutSolidCube(1.0);
            glPopMatrix();
            //leg
            glPushMatrix();
            glTranslatef(0.70,-2.15,0.45);
            glScalef(0.1,0.3,0.1);
            glutSolidCube(1.0);
            glPopMatrix();
            //leg
            glPushMatrix();
            glTranslatef(-0.70,-2.15,-0.45);
            glScalef(0.1,0.3,0.1);
            glutSolidCube(1.0);
            glPopMatrix();
            //leg
            glPushMatrix();
            glTranslatef(0.70,-2.15,-0.45);
            glScalef(0.1,0.3,0.1);
            glutSolidCube(1.0);
            glPopMatrix();
            //leg
            glPushMatrix();
            glTranslatef(-0.70,-2.15,0.45);
            glScalef(0.1,0.3,0.1);
            glutSolidCube(1.0);
            glPopMatrix();
            // door handle
            glPushMatrix();
             glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diff2);
            glColor3f(0.90, 0.70, 0.53);
            glTranslatef(0.5,-0.3,.5);
            glutSolidSphere(0.1,100,100);
            glPopMatrix();
}
void draw_a_table(void){
            GLfloat matdiff1[]={0.95, 0.72, 0.49,1.0};
            glColor3f(0.95, 0.72, 0.49);
            glMaterialfv(GL_FRONT,GL_DIFFUSE,matdiff1);
            glPushMatrix();
                glScalef(3.0,0.3,3.0);
                glutSolidCube(1.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(1.5,-1.0,1.5);
                glScalef(0.1,2.0,0.1);
                glutSolidCube(1.0);
            glPopMatrix();
             glPushMatrix();
                glTranslatef(-1.5,-1.0,-1.5);
                glScalef(0.1,2.0,0.1);
                glutSolidCube(1.0);
            glPopMatrix();
             glPushMatrix();
                glTranslatef(-1.5,-1.0,1.5);
                glScalef(0.1,2.0,0.1);
                glutSolidCube(1.0);
            glPopMatrix();
             glPushMatrix();
                glTranslatef(1.5,-1.0,-1.5);
                glScalef(0.1,2.0,0.1);
                glutSolidCube(1.0);
            glPopMatrix();


}
void draw_furniture_at_opposite_Z(void){
      //furniture
     glPushMatrix();
        //first table
        glPushMatrix();
            glColor3f(0.95, 0.72, 0.49);
            glTranslatef(5.0,-4.8,8.0);
            //glRotatef(13,1.0,0.0,0.0);
            //glRotatef(45,0.0,1.0,0.0);
            draw_a_table();
        glPopMatrix();
        //second table
        glPushMatrix();
            glColor3f(0.95, 0.72, 0.49);
            glTranslatef(-6.0,-4.8,6.0);
            //glRotatef(13,1.0,0.0,0.0);
            //glRotatef(135,0.0,1.0,0.0);
            draw_a_table();
        glPopMatrix();
        //thrird table
        glPushMatrix();
            glTranslatef(-1.0,-4.8,17.0);
            //glRotatef(13,1.0,0.0,0.0);
           // glRotatef(45,0.0,1.0,0.0);
            draw_a_table();
        glPopMatrix();
        //forth table
        glPushMatrix();
            glTranslatef(-18.0,-4.8,13.0);
            //glRotatef(13,1.0,0.0,0.0);
           // glRotatef(45,0.0,1.0,0.0);
            draw_a_table();
        glPopMatrix();
                //fifth table
        glPushMatrix();
            glTranslatef(+15.0,-4.8,6.0);
            //glRotatef(13,1.0,0.0,0.0);
           // glRotatef(45,0.0,1.0,0.0);
            draw_a_table();
        glPopMatrix();
        //first closet
        glPushMatrix();
        glTranslatef(2.0,-4.4,18.0);
        //glRotatef(30,0.0,1.0,0.0);
            draw_a_closet();
        glPopMatrix();
        //second closet
        glPushMatrix();
            glTranslatef(20.0,-4.4,18.0);
            draw_a_closet();
        glPopMatrix();
        //third closet
        glPushMatrix();
            glTranslatef(-19.0,-4.4,18.0);
            draw_a_closet();
        glPopMatrix();
        //forth closet
        glPushMatrix();
            glTranslatef(23.0,-4.4,9.0);
            glRotatef(-90,0.0,1.0,0.0);
            draw_a_closet();
        glPopMatrix();
        //the fifth closet
        glPushMatrix();
            glTranslatef(-23.0,-4.4,8.5);
            glRotatef(90,0.0,1.0,0.0);
            draw_a_closet();
        glPopMatrix();
     glPopMatrix();


}
void draw_a_window(void){
    GLfloat mat_diff1[]={0.69, 0.46, 0.05,1.0};
    GLfloat mat_diff2[]={0.0,0.0,0.0,1.0};
    GLfloat mat_diff3[]={0.87, 0.92, 0.96,1.0};
    //window frame
    glPushMatrix();
        glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diff1);
        glColor3f(0.69, 0.46, 0.05);
        glutWireCube(1.0);
    glPopMatrix();
    //window backgound
    glPushMatrix();
        glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diff3);
        glColor3f(0.87, 0.92, 0.96);
        glutSolidCube(0.9);
    glPopMatrix();
    //window fence
    glPushMatrix();
        glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diff2);
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINES);
            glVertex3f(-.5,0.0,0.5);
            glVertex3f(.5,0.0,0.5);
            glVertex3f(0.0,-.5,0.5);
            glVertex3f(0.0,.5,0.5);
            glEnd();
    glPopMatrix();
    }
void draw_a_light_lamp(void){
    GLfloat conemat[]={1.0,1.0,0.0,.8};
    GLfloat light_direc[]={0.0,-1.0,0.0};
    GLfloat light_pos[]={0.0,5,0.0,1.0};
    GLfloat light_spec[]={1.0,1.0,1.0,1.0};
    GLfloat light_diff[]={1.0,1.0,1.0,1.0};
    const GLfloat light_cutoff=85.0;

    glPushMatrix();
        glColor3f(1.0,1.0,0.0);
        glTranslatef(0.0,3.8,0.0);
        glScalef(0.1,2.0,0.1);
        glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,light_direc);
        glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,light_cutoff);
        glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diff);
        glLightfv(GL_LIGHT0,GL_SPECULAR,light_spec);
        glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
        glRotatef(-90.0,1,0,0);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,conemat);
        glutSolidCone(2.0,3,100,100);
    glPopMatrix();
    glPushMatrix();
        //glColor3f(1.00, 0.79, 0.16);
        glTranslatef(0.0,1.0,0.0);
        glutSolidSphere(1.0,100,100);
    glPopMatrix();
}
void background(void){
    GLfloat matdiff1[]={0.29, 0.00, 0.38,1.0};
    GLfloat matdiff2[]={0.50, 0.00, 0.64,1.0};
    GLfloat matdiff3[]={0.22, 0.00, 0.29,1.0};
    glPushMatrix();
     //furniture
     glPushMatrix();
        //first table
        glPushMatrix();
            //glColor3f(0.95, 0.72, 0.49);
            glTranslatef(5.0,-4.8,-8.0);
            //glRotatef(13,1.0,0.0,0.0);
            //glRotatef(45,0.0,1.0,0.0);
            draw_a_table();
        glPopMatrix();
        //second table
        glPushMatrix();
            //glColor3f(0.95, 0.72, 0.49);
            glTranslatef(-6.0,-4.8,-6.0);
            //glRotatef(13,1.0,0.0,0.0);
            //glRotatef(135,0.0,1.0,0.0);
            draw_a_table();
        glPopMatrix();
        //thrird table
        glPushMatrix();
            glTranslatef(-1.0,-4.8,-17.0);
            draw_a_table();
        glPopMatrix();
        //forth table
        glPushMatrix();
            glTranslatef(-18.0,-4.8,-13.0);
            draw_a_table();
        glPopMatrix();
                //fifth table
        glPushMatrix();
            glTranslatef(+15.0,-4.8,-6.0);
            draw_a_table();
        glPopMatrix();
        //first closet
        glPushMatrix();
        glTranslatef(2.0,-4.4,-18.0);
        //glRotatef(30,0.0,1.0,0.0);
            draw_a_closet();
        glPopMatrix();
        //second closet
        glPushMatrix();
            glTranslatef(20.0,-4.4,-18.0);
            draw_a_closet();
        glPopMatrix();
        //third closet
        glPushMatrix();
            glTranslatef(-19.0,-4.4,-18.0);
            draw_a_closet();
        glPopMatrix();
        //forth closet
        glPushMatrix();
            glTranslatef(23.0,-4.4,-9.0);
            glRotatef(-90,0.0,1.0,0.0);
            draw_a_closet();
        glPopMatrix();
        //the fifth closet
        glPushMatrix();
            glTranslatef(-23.0,-4.4,-8.5);
            glRotatef(90,0.0,1.0,0.0);
            draw_a_closet();
        glPopMatrix();
     glPopMatrix();
     //furniture at oppostie z
     draw_furniture_at_opposite_Z();
     //roof,ground and walls
     glPushMatrix();
        //the roof
        glPushMatrix();
            glMaterialfv(GL_FRONT,GL_DIFFUSE,matdiff1);
            glColor4f(0.29, 0.00, 0.38,1.0);
            glTranslatef(0.0,7.0,0.0);
            glRotatef(180,0.0,0.0,1.0);
            glScalef(50.0,1.0,40.0);
            glutSolidCube(1.0);
        glPopMatrix();
        //the ground
            glPushMatrix();
                glEnable (GL_BLEND);
                glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
                glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,matdiff1);
                glColor4f(0.29, 0.00, 0.38,1.0);
                glTranslatef(0.0,-7.0,0.0);
                glScalef(50.0,0.5,40.0);
                glutSolidCube(1.0);
            glPopMatrix();
            //the forground wall with windows
            glPushMatrix();
                glTranslatef(0.0,0.0,-20.0);
                //foreground wall only
                glPushMatrix();
                    glEnable (GL_BLEND);
                    glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
                    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,matdiff2);
                    glColor4f(0.50, 0.00, 0.64,1.0);
                    glScalef(50.0,14,1.0);
                    glutSolidCube(1.0);
                glPopMatrix();
                //the 1st window
                    glPushMatrix();
                        glTranslatef(-20.0,0.0,1.0);
                        glScalef(3.0,3.0,0.05);
                        draw_a_window();
                    glPopMatrix();
                    //the 2st window
                    glPushMatrix();
                        glTranslatef(20.0,0.0,1.0);
                        glScalef(3.0,3.0,0.05);
                        draw_a_window();
                    glPopMatrix();
                    //the 3st window
                    glPushMatrix();
                        glTranslatef(0.0,0.0,1.0);
                        glScalef(3.0,3.0,0.05);
                        draw_a_window();
                    glPopMatrix();
            glPopMatrix();
        glPopMatrix();
            //the background wall with a door and windows
            glPushMatrix();
                glTranslatef(0.0,0.0,20.0);
                //background wall only
                glPushMatrix();
                    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,matdiff2);
                    glEnable (GL_BLEND);
                    glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
                    glColor4f(0.50, 0.00, 0.64,1.0);
                    glScalef(50.0,14,1.0);
                    glutSolidCube(1.0);
                glPopMatrix();
                //the door
                glPushMatrix();
                    glTranslatef(10.0,-4.5,-0.5);
                    glRotatef(180.0,0.0,1.0,0.0);
                    draw_a_door();
                glPopMatrix();
                //the 1st window
                glPushMatrix();
                        glTranslatef(-20.0,0.0,-1.0);
                        glRotatef(180.0,0.0,1.0,0.0);
                        glScalef(3.0,3.0,0.05);
                        draw_a_window();
                glPopMatrix();
                    //the 2st window
                glPushMatrix();
                        glTranslatef(20.0,0.0,-1.0);
                        glRotatef(180.0,0.0,1.0,0.0);
                        glScalef(3.0,3.0,0.05);
                        draw_a_window();
                glPopMatrix();
                    //the 3st window
                glPushMatrix();
                        glTranslatef(0.0,0.0,-1.0);
                        glRotatef(180.0,0.0,1.0,0.0);
                        glScalef(3.0,3.0,0.05);
                        draw_a_window();
                glPopMatrix();
            glPopMatrix();
            //the right wall with windows
            glPushMatrix();
                glTranslatef(25.0,0.0,0.0);
                glPushMatrix();
                glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,matdiff3);
                glColor3f(0.22, 0.00, 0.29);
                glScalef(1.0,14.0,40.0);
                glutSolidCube(1.0);
                glPopMatrix();
                    //1st window
                    glPushMatrix();
                        glTranslatef(-1.0,0.0,11.0);
                        glRotatef(-90,0.0,1.0,0.0);
                        glScalef(3.0,3.0,0.05);
                        draw_a_window();
                    glPopMatrix();
                    //the 2st window
                    glPushMatrix();
                        glTranslatef(-1.0,0.0,0.0);
                        glRotatef(-90,0.0,1.0,0.0);
                        glScalef(3.0,3.0,0.05);
                        draw_a_window();
                    glPopMatrix();
                    //the 3st window
                    glPushMatrix();
                        glTranslatef(-1.0,0.0,-11.0);
                        glRotatef(-90,0.0,1.0,0.0);
                        glScalef(3.0,3.0,0.05);
                        draw_a_window();
                    glPopMatrix();
           glPopMatrix();
             //the left wall with windows
            glPushMatrix();
                glTranslatef(-25.0,0.0,0.0);
                //left wall only
                glPushMatrix();
                glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,matdiff3);
                glColor3f(0.22, 0.00, 0.29);
                glScalef(1.0,14.0,40.0);
                glutSolidCube(1.0);
                glPopMatrix();
                //the 1st window
                    glPushMatrix();
                        glTranslatef(1.0,0.0,0.0);
                        glRotatef(90,0.0,1.0,0.0);
                        glScalef(3.0,3.0,0.05);
                        draw_a_window();
                    glPopMatrix();
                    //the 2st window
                    glPushMatrix();
                         glTranslatef(1.0,0.0,11.0);
                         glRotatef(90,0.0,1.0,0.0);
                        glScalef(3.0,3.0,0.05);
                        draw_a_window();
                    glPopMatrix();
                    //the 3st window
                    glPushMatrix();
                         glTranslatef(1.0,0.0,-11.0);
                         glRotatef(90,0.0,1.0,0.0);
                        glScalef(3.0,3.0,0.05);
                        draw_a_window();
                    glPopMatrix();

        //closing the push matrix of the walls and roofs
        glPopMatrix();
        //the lamp
        glPushMatrix();
            glScalef(0.4,0.4,0.4);
            glTranslatef(0.0,6.0,0.0);
            draw_a_light_lamp();
        glPopMatrix();
        //closing the pushmatrix of the whole background function
    glPopMatrix();


}
void robot_model(void){
    GLfloat mat1[]={0.72, 0.66, 0.76,1.0};
    GLfloat mat2[]={0.45, 0.46, 0.47,1.0};
    GLfloat mat3[]={0.69, 0.60, 0.72,1.0};
    GLfloat mat4[]={0.00, 0.00, 0.01,1.0};
    GLfloat mat5[]={0.43, 0.36, 0.47,1.0};
    GLfloat mat6[]={0.45, 0.46, 0.47,1.0};
    GLfloat mat7[]={0.54, 0.47, 0.58,1.0};
    GLfloat mat8[]={0.69, 0.22, 0.16,1.0};
    GLfloat mat9[]={0.43, 0.36, 0.47,1.0};
    GLfloat mat10[]={0.17, 0.17, 0.17,1.0};
    GLfloat mat11[]={0.26, 0.27, 0.27,1.0};
    GLfloat mat12[]={iris1, iris2, iris3,1.0};

     glPushMatrix();

        glScalef(.6,.6,.6);

        glTranslatef(xpos,whole_robot,zpos);
        glRotatef(GLfloat(view_angle),0.0,1.0,0.0);




        glPushMatrix();
        //main cone
        glMaterialfv(GL_FRONT,GL_DIFFUSE,mat1);
        glColor3f(0.72, 0.66, 0.76);
        glRotatef(90.0,1.0,0.0,0.0);
        glScalef(1,1,1);
        glutSolidCone(0.8,2,10,10);
        glPopMatrix();

        //the head and neck
        glPushMatrix();
                glTranslatef(0.0,0.12,0.0);
                glRotatef((GLfloat)neck,0.0,1.0,0.0);
                //the neck
                glPushMatrix();
                glMaterialfv(GL_FRONT,GL_DIFFUSE,mat2);
                glColor3f(0.45, 0.46, 0.47);
                glScalef(0.5,0.25,.3);
                glutSolidCube(1.0);
        glPopMatrix();
            // the head
            glPushMatrix();
                glMaterialfv(GL_FRONT,GL_DIFFUSE,mat3);
                glColor3f(0.69, 0.60, 0.72);
                glTranslatef(0.0,1.0,0.0);
                glScalef(0.5,1.0,0.5);
                glutSolidSphere(1.0,100,100);
            glPopMatrix();
            //iris
            glPushMatrix();
                glMaterialfv(GL_FRONT,GL_DIFFUSE,mat12);
                glColor3f(iris1,iris2,iris3);
                glTranslatef(0.0,1.0,0.4);
                glScalef(0.2,0.4,0.15);
                glutSolidSphere(1.0,100,100);
            glPopMatrix();
            //pupil
                glPushMatrix();
                glTranslatef(0.0,1.0,0.6);
                glMaterialfv(GL_FRONT,GL_DIFFUSE,mat4);
                glColor3f(0.00, 0.00, 0.01);
                glScalef(0.1,0.4,0.1);
                glutSolidCube(1.0);
            glPopMatrix();
        glPopMatrix();

        //the right terminal
        glPushMatrix();
        glMaterialfv(GL_FRONT,GL_DIFFUSE,mat5);
        glColor3f(0.43, 0.36, 0.47);
        glTranslatef(0.7,-.1,0.0);
        glRotatef((GLfloat) right_shoulder_y,0.0,1.0,0.0);
        glRotatef((GLfloat)right_shoulder_z,0.0,0.0,1.0);
        glTranslatef(0.7,0.0,0.0);

         glPushMatrix();
        // the right shoulder
        glScalef(1.2,0.2,0.3);
        glutSolidCube(1.0);
        glPopMatrix();
        //the right shoulder ball
        glPushMatrix();
            glMaterialfv(GL_FRONT,GL_DIFFUSE,mat6);
            glColor3f(0.45, 0.46, 0.47);
            glTranslatef(-0.35,0.0,0.0);
            glScalef(0.24,0.18,0.3);
            glutWireSphere(1.0,100,100);
        glPopMatrix();

        //the right elbow
        glTranslatef(0.6,0.0,0.0);
        glRotatef((GLfloat)right_elbow,0.0,0.0,1.0);
        glTranslatef(.75,0.0,0.0);
        glPushMatrix();
            glScalef(1.5,0.2,.3);
            glutWireCube(1.0);
        glPopMatrix();

        //the right hand
        glTranslatef(0.9,0.0,0.0);
        glMaterialfv(GL_FRONT,GL_DIFFUSE,mat7);
        glColor3f(0.54, 0.47, 0.58);
        glPushMatrix();
            glRotatef(90.0,0.0,0.0,1.0);
            glScalef(.2,0.2,0.4);
            glutSolidSphere(1.0,100,100);
        glPopMatrix();

        //the first finger
        glPushMatrix();
            glRotatef((GLfloat)right_first_finger,0.0,0.0,1.0);
            glTranslatef(.5,0.05,0.0);
            glScalef(.6,0.1,0.1);
            glutSolidCube(1.0);
        glPopMatrix();

        //the second finger
        glPushMatrix();
            glRotatef((GLfloat)right_second_finger,0.0,0.0,1.0);
            glTranslatef(.5,-0.05,0.0);
            glScalef(.6,0.1,0.1);
            glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();

        //the left terminal
        glPushMatrix();
            glMaterialfv(GL_FRONT,GL_DIFFUSE,mat5);
            glColor3f(0.43, 0.36, 0.47);
            glTranslatef(-0.7,-.1,0.0);
            glRotatef((GLfloat) left_shoulder_y,0.0,1.0,0.0);
            glRotatef((GLfloat)left_shoulder_z,0.0,0.0,1.0);
            glTranslatef(-0.7,0.0,0.0);

        // the left shoulder
            glPushMatrix();
                glScalef(1.2,0.2,0.3);
                glutSolidCube(1.0);
            glPopMatrix();

             //the left shoulder ball
            glPushMatrix();
                glMaterialfv(GL_FRONT,GL_DIFFUSE,mat6);
                glColor3f(0.45, 0.46, 0.47);
                glTranslatef(0.35,0.0,0.0);
                glScalef(0.24,0.18,0.3);
                glutWireSphere(1.0,100,100);
            glPopMatrix();

         //the left elbow
            glTranslatef(-0.6,0.0,0.0);
            glRotatef((GLfloat)left_elbow,0.0,0.0,1.0);
            glTranslatef(-.75,0.0,0.0);
            glPushMatrix();
                glScalef(1.5,0.2,.3);
                glutWireCube(1.0);
            glPopMatrix();

        //the left hand with fingers
            glTranslatef(-0.9,0.0,0.0);
            glRotatef((GLfloat)left_hand_angle,0.0,0.0,1.0);
            glMaterialfv(GL_FRONT,GL_DIFFUSE,mat7);
            glColor3f(0.54, 0.47, 0.58);
            //the hand only
            glPushMatrix();
                glScalef(.2,0.2,0.4);
                glutSolidSphere(1.0,100,100);
            glPopMatrix();

        //the first finger
            glPushMatrix();
                glRotatef((GLfloat)left_first_finger,0.0,0.0,1.0);
                glTranslatef(-.5,0.05,0.0);
                glScalef(.6,0.1,0.1);
                glutSolidCube(1.0);
            glPopMatrix();

        //the second finger
            glPushMatrix();
            glRotatef((GLfloat)left_second_finger,0.0,0.0,1.0);
            glTranslatef(-.5,-0.05,0.0);
                glPushMatrix();
                    glScalef(.6,0.1,0.1);
                    glutSolidCube(1.0);
                glPopMatrix();
         //teapot
                glPushMatrix();
                    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat8);
                    glEnable(GL_BLEND);
                    glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
                    glColor4f(0.69, 0.22, 0.16,teapot_trans);
                    glTranslatef(-1.0,0.0,0.0);
                    glRotatef(180.0,0.0,1.0,0.0);
                    glutSolidTeapot(.5);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();


        //schock absorber(axis and wire cube)

        //the axis
        glPushMatrix();
            glTranslatef(0.0,-2.2,0.0);
            glMaterialfv(GL_FRONT,GL_DIFFUSE,mat9);
            glColor3f(0.43, 0.36, 0.47);
            glScalef(0.1,.8,0.1);
            glutSolidCube(1.0);
        glPopMatrix();

        glTranslatef(0.0,axis,0.0);//
        //the wire cube
        glPushMatrix();
            glScalef(0.3,1.0,0.2);
            glutWireCube(1.0);
        glPopMatrix();
        //axix tier
        glPushMatrix();
            glTranslatef(0.0,-1.4,0.0);
            glRotatef((GLfloat)tier_angle,1.0,0.0,0.0);
            glMaterialfv(GL_FRONT,GL_DIFFUSE,mat10);
            glColor3f(0.17, 0.17, 0.17);
            glScalef(0.4,.9,.9);
            glutSolidSphere(1.0,10,10);
        glPopMatrix();
   glPopMatrix();
}
void display(void)
{

   glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

   glPushMatrix();
        glRotatef((GLfloat)all_on_y,0.0,1.0,0.0);
         robot_model();
         background();
   glPopMatrix();
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(70.0, (GLfloat) w/(GLfloat) h, 1.0, 70.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -10.0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 's':
          if(right_shoulder_z>-90){
                right_shoulder_z = (right_shoulder_z - 5);
                glutPostRedisplay();}
         break;
      case 'S':
          if(right_shoulder_z<90){
         right_shoulder_z = (right_shoulder_z + 5);
         glutPostRedisplay();}
         break;
      case 'x':
          if(right_shoulder_y>-90){
                right_shoulder_y = (right_shoulder_y - 5);
                glutPostRedisplay();}
         break;
      case 'X':
          if(right_shoulder_y<90){
         right_shoulder_y = (right_shoulder_y + 5);
         glutPostRedisplay();}
         break;
      case 'w':
                right_elbow = (right_elbow +5)%360;
                glutPostRedisplay();
         break;
      case 'W':

                right_elbow = (right_elbow - 5)%360;
                glutPostRedisplay();
         break;
         case 'd':
             if(left_shoulder_z<90){
                left_shoulder_z = (left_shoulder_z + 5);
                glutPostRedisplay();}
         break;
      case 'D':
          if(left_shoulder_z>-90){
                left_shoulder_z = (left_shoulder_z - 5);
                glutPostRedisplay();}
         break;
      case 'c':
             if(left_shoulder_y<90){
                left_shoulder_y = (left_shoulder_y + 5);
                glutPostRedisplay();}
         break;
      case 'C':
          if(left_shoulder_y>-90){
                left_shoulder_y = (left_shoulder_y - 5);
                glutPostRedisplay();}
         break;
      case 'e':
         left_elbow = (left_elbow + 5) % 360;
         glutPostRedisplay();
         cout<<left_elbow;
         break;
      case 'E':
         left_elbow = (left_elbow - 5) % 360;
         glutPostRedisplay();
         cout<<left_elbow;
         break;
      case 't':

          if(left_first_finger<=0){
                cout<<"t\n";
                left_first_finger = (left_first_finger + 1);
                glutPostRedisplay();}
         break;
      case 'T':
          if(left_first_finger==0||left_first_finger>=-30){
         left_first_finger = (left_first_finger -1);
         glutPostRedisplay();}
         break;
      case 'y':

          if(left_second_finger>=0){
                cout<<"y\n";
                left_second_finger = (left_second_finger - 1);
                glutPostRedisplay();}
         break;
      case 'Y':
          if(left_second_finger==0||left_second_finger<=30){
         left_second_finger= (left_second_finger +1);
         glutPostRedisplay();}
         break;
       case 'g':

          if(right_first_finger>=0){
                cout<<"g\n";
                right_first_finger = (right_first_finger - 1);
                glutPostRedisplay();}
         break;
      case 'G':
          if(right_first_finger==0||right_first_finger<=30){
         right_first_finger = (right_first_finger +1);
         glutPostRedisplay();}
         break;
      case 'h':

          if(right_second_finger<=0){
                cout<<"h\n";
                right_second_finger = (right_second_finger + 1);
                glutPostRedisplay();}
         break;
      case 'H':
          if(right_second_finger==0||right_second_finger>=-30){
         right_second_finger = (right_second_finger -1);
         glutPostRedisplay();}
         break;
       case 'n':
                neck = (neck +5)%360;
                glutPostRedisplay();
         break;
      case 'N':

                neck = (neck - 5)%360;
                glutPostRedisplay();
         break;
      case 'u':
        if(dancing==false){
            if(shock_absorber_bool==false){
                shock_absorber_bool=true;
                axis+=0.8;
                whole_robot-=0.8;
                glutPostRedisplay();
                //cout<<whole_robot;

            }
            else {
                shock_absorber_bool=false;
                axis-=0.8;
                whole_robot+=0.8;
                glutPostRedisplay();
                //cout<<whole_robot;

            }}
        break;
      case '2' :

            view_angle=180;
            zpos-=0.1;
            tier_angle = (tier_angle + 30) % 360;
            glutPostRedisplay();
            cout<<"up arrow "<<xpos<<"\t"<<zpos<<endl;
            break;
      case '6':

            view_angle=270;
            xpos-=0.1;
            tier_angle = (tier_angle + 30) % 360;
            glutPostRedisplay();

            cout<<"left arrow "<<xpos<<"\t"<<zpos<<endl;
            break;
       case '8':

            view_angle=0;
            zpos+=0.1;
            tier_angle = (tier_angle + 30) % 360;
            glutPostRedisplay();
            cout<<"down arrow "<<xpos<<"\t"<<zpos<<endl;
            break;
       case '4':

            view_angle=90;
            xpos+=0.1;
            tier_angle = (tier_angle + 30) % 360;
            glutPostRedisplay();
            cout<<"right arrow "<<xpos<<"\t"<<zpos<<endl;
            break;

         case 'p':
                all_on_y = (all_on_y +5)%360;
                glutPostRedisplay();
                cout<<"p is "<<all_on_y;
         break;
      case 'P':

                all_on_y = (all_on_y - 5)%360;
                glutPostRedisplay();
                cout<<"p is "<<all_on_y;
         break;
      case 'l':
          iris1=1.0,iris2=0.0,iris3=0.0;
          shock_absorber_bool=false/*whole_robot=-6.0*/,axis=-3.0;
          dance_1_bool=false,dancing=true;
          neck=-75;
          right_elbow=-30,left_elbow=30,right_shoulder_y=0,left_shoulder_y=0,right_shoulder_z=50,left_shoulder_z=-50;;
          glutIdleFunc(animation1);
          break;
      case 'k':
            iris1=0.0,iris2=1.0,iris3=0.0;
            right_shoulder_z=0,left_shoulder_z=0,right_shoulder_y=0,left_shoulder_y=0,right_elbow=-90,left_elbow=90,neck=0;
            dance_2_bool=false,dancing=true;
            glutIdleFunc(animation2);
        break;
      case 'j':
          if((xpos>=-15.8&&xpos<=-13.9&&zpos>=-12.3&&zpos<=-7.7)||(xpos>=2.3&&xpos<=4.4&&zpos>=-14.2&&zpos<=-10.5)||(xpos>=-7.5&&xpos<-5.4&&zpos>=-29.5&&zpos<=-25.8)){
                shock_absorber_bool=true,axis+=0.8,whole_robot-=0.8,dancing=true;
                view_angle=90,left_hand_bool=false;
                left_shoulder_y=89,left_shoulder_z=25,left_elbow=-60,teapot_trans=1.0,left_first_finger=0,left_second_finger=0;
                glutIdleFunc(animation3);}
            break;
      case ';':
            left_shoulder_z=-20,left_elbow=-20,view_angle=0;
            shock_absorber_bool=false,whole_robot=-6.0,axis=-3.0;
            dancing=true,dance_4_bool=false;
            glutIdleFunc(animation4);
            break;
      case 'L':
            teapot_trans=0.0,left_hand_angle=0.0,left_first_finger=-10,left_second_finger=10;
            dancing=false;
            shock_absorber_bool=false,whole_robot=-6.0,axis=-3.0;
            iris1=0.81,iris2=0.82,iris3=0.26;
            neck=0,left_elbow=0,right_elbow=0,left_shoulder_z=0,right_shoulder_z=0,right_shoulder_y=0,left_shoulder_y=0;
            glutPostRedisplay();
            glutIdleFunc(NULL);
            break;
      default:
         break;
   }
}
void myfunc(int key,int x,int y){
    switch(key){
    case GLUT_KEY_UP:
            view_angle=180,zpos-=0.1;
            tier_angle = (tier_angle + 30) % 360;
            glutPostRedisplay();
            cout<<"up arrow "<<xpos<<"\t"<<zpos<<endl;
            break;
    case GLUT_KEY_DOWN:
            view_angle=0,zpos+=0.1;
            tier_angle = (tier_angle + 30) % 360;
            glutPostRedisplay();
            cout<<"down arrow "<<xpos<<"\t"<<zpos<<endl;
            break;
    case GLUT_KEY_RIGHT:
        view_angle=90,xpos+=0.1;
            tier_angle = (tier_angle + 30) % 360;
            glutPostRedisplay();
            cout<<"right arrow "<<xpos<<"\t"<<zpos<<endl;
            break;
    case GLUT_KEY_LEFT:
        view_angle=270,xpos-=0.1;
            tier_angle = (tier_angle + 30) % 360;
            glutPostRedisplay();
            cout<<"left arrow "<<xpos<<"\t"<<zpos<<endl;
            break;
    default:
        break;

    }


}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(myfunc);
   glutMainLoop();
   return 0;
}
