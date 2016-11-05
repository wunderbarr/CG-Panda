/*
 * Basics of Computer Graphics Exercise
 */
 
#include "assignment.h"
using namespace std;

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

/*Custom Transformations*/

glm::mat4 customScaling(float a, float b, float c=0.0f);
glm::mat4 customTranslation(float a, float b, float c=0.0f);
glm::mat4 customRotation(float ang);


void drawScene(int scene, float runTime) 
{

    /*draw Circles*/

    drawCircle( glm::vec3(0.0f, 0.0f, 1.0f), customScaling(0.9f,0.9f));
    drawCircle( glm::vec3(0.2f, 0.2f, 0.2f), customScaling(0.88f,0.88f));  
    drawCircle( glm::vec3(0.0f, 0.0f, 1.0f), customScaling(0.68f,0.68f));
    drawCircle( glm::vec3(0.0f, 0.0f, 0.0f), customScaling(0.66f,0.66f));

    /*draw spectator stand*/
    
    drawCircle( glm::vec3(0.4f, 0.4f, 0.4f),  customTranslation(-0.95f,0.0f) * customScaling(0.035f,0.6f));  
    
    /*draw start/finish line*/

    for(int i=-4; i<5; i++)
        drawCircle( glm::vec3(1.0f, 1.0f, 1.0f),  customTranslation(-0.78f+i*0.02f,0.0f) * customScaling(0.005f,0.03f));  

    /*draw dotted line between lanes*/

    for(int i=0; i<30; i++)
        drawCircle( glm::vec3(1.0f, 1.0f, 1.0f),  customRotation(i * M_PI/15 + M_PI/30) * customTranslation(-0.78f,0.0f) * customScaling(0.01f,0.03f));  

    /*draw the racers*/

    drawCircle( glm::vec3(1.0f, 1.0f, 0.0f),  customRotation(-runTime * M_PI/8) * customTranslation(-0.73f,0.0f) * customScaling(0.025f,0.075f));  
    drawCircle( glm::vec3(0.0f, 1.0f, 0.0f),  customRotation(-runTime * M_PI/4) * customTranslation(-0.83f,0.0f) * customScaling(0.020f,0.100f));  

    /*
     *if(runTime < 1.5)
     *{
     *    glm::mat3 m1(1,0,0,  0,1,0,  -1.5,-1.5,1);
     *    glm::mat3 m2(0.707,0.707,0,  -0.707,0.707,0,  0,0,1);
     *    glm::mat3 m3(2.828,0,0,  0,1.414,0,  0,0,1);
     *    glm::mat3 m4(1,0,0,  0,1,0,  4,2,1);
     *    glm::mat3 m = m4 * m3 * m2 * m1;
     *    for(int i=0; i<3; i++)
     *        for(int j=0; j<3; j++)
     *            cout << m[i][j] << " ";
     *    cout << endl;
     *}
     */

}

void initCustomResources()
{
}

void deleteCustomResources()
{
}

glm::mat4 customScaling(float a, float b, float c)
{
    glm::vec4 S_1(a, 0.0f, 0.0f, 0.0f);
    glm::vec4 S_2(0.0f, b, 0.0f, 0.0f);
    glm::vec4 S_3(0.0f, 0.0f, c, 0.0f);
    glm::vec4 S_4(glm::vec3(0.0f), 1.0f);
    return glm::mat4(S_1, S_2, S_3, S_4);
}

glm::mat4 customTranslation(float a, float b, float c)
{
    glm::vec4 T_1(1.0f, glm::vec3(0.0f));
    glm::vec4 T_2(0.0f, 1.0f, 0.0f, 0.0f);
    glm::vec4 T_3(0.0f, 0.0f, 1.0f, 0.0f);
    glm::vec4 T_4(a, b, c, 1.0f);
    return glm::mat4(T_1, T_2, T_3, T_4);
}

glm::mat4 customRotation(float ang) 
{
    glm::vec4 R_1(cos(ang), sin(ang), 0.0f, 0.0f);
    glm::vec4 R_2(-sin(ang), cos(ang), 0.0f, 0.0f);
    glm::vec4 R_3(0.0f, 0.0f, 1.0f, 0.0f);
    glm::vec4 R_4(glm::vec3(0.0f), 1.0f);
    return glm::mat4(R_1, R_2, R_3, R_4);
}
