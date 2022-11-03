uniform sampler2D texture;
varying vec4 vert_pos;

uniform bool hasTexture;
uniform vec2 lightPos;

void main(void)
{
   // gl_FragColor = texture2D(qt_Texture0, qt_TexCoord0.st);

    //Ambient light
            vec4 ambient = vec4(0.02, 0.02, 0.02, 1);

            //Convert light to view coords
            lightPos.xy = (gl_ModelViewProjectionMatrix * vec4(lightPos, 0, 1));


            //Calculate the vector from light to pixel (Make circular)
            vec2 lightToFrag = lightPos - vert_pos.xy;
            lightToFrag.y = lightToFrag.y / 1.7;

            //Length of the vector (distance)
            float vecLength = clamp(length(lightToFrag) * 4, 0, 1);

        // lookup the pixel in the texture
        vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

        // multiply it by the color and lighting
            if(hasTexture == true)
            {
                    gl_FragColor = gl_Color * pixel * (clamp(ambient + vec4(1-vecLength, 1-vecLength, 1-vecLength, 1), 0, 1));
            }
            else
            {
                    gl_FragColor = gl_Color;
            }
}
