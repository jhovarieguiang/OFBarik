#version 120
//this is currently works

uniform sampler2DRect texturemaskguide;
uniform sampler2DRect imageMask;

varying vec2 texCoordVarying;

void main()
{
    vec4 rTxt = texture2DRect(texturemaskguide, texCoordVarying);
    vec4 mask = texture2DRect(imageMask, texCoordVarying);
    
    vec4 color = vec4(0, 0, 0, 0);
    color = vec4(mask.r,mask.g,mask.b,rTxt.a); //alphamask
    
    gl_FragColor = color;
}
