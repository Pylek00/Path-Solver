attribute vec4 qt_Vertex;
attribute vec4 qt_MultiTexCoord0;
uniform mat4 qt_ModelViewProjectionMatrix;
varying vec4 qt_TexCoord0;

void main(void)
{
    gl_Position = qt_ModelViewProjectionMatrix * qt_Vertex;
    qt_TexCoord0 = qt_MultiTexCoord0;


    // transform the vertex position
        qt_TexCoord0 = gl_ModelViewProjectionMatrix * gl_Vertex;
        gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

        // transform the texture coordinates
        gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;

        // forward the vertex color
        gl_FrontColor = gl_Color;

}
