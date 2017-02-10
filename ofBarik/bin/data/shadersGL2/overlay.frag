#version 120
//this is currently works

//uniform sampler2DRect texturemaskguide;
//uniform sampler2DRect imageMask;
uniform sampler2DRect texturefront;
uniform sampler2DRect textureback;

varying vec2 texCoordVarying;

void main()
{
    vec4 rTxt = texture2DRect(texturefront, texCoordVarying);
    vec4 mask = texture2DRect(textureback, texCoordVarying);
    
    vec4 color = vec4(0, 0, 0, 0);
    color = mix(mask, rTxt, rTxt.a);//overlay
   // color = vec4(mask.r,mask.g,mask.b,rTxt.a); //alphamask
    
    gl_FragColor = color;
}
