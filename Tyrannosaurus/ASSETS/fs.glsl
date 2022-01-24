
#version 330 core
out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;


void main()
{
   //FragColor = vec4(ourColor, 1.0);
   FragColor = texture(ourTexture, TexCoord);
   //FragColor = mix(texture(ourTexture, TexCoord) ,texture(ourTexture2, TexCoord) ,0.9);
}