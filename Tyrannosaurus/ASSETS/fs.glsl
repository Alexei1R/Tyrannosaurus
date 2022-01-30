
#version 330 core
out vec4 FragColor;
  
in vec2 TexCoord;

uniform sampler2D ourTexture;


void main()
{
   FragColor = texture(ourTexture, TexCoord);
   //FragColor = mix(texture(ourTexture, TexCoord) ,texture(ourTexture2, TexCoord) ,0.9);
}