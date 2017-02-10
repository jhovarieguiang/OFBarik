#version 150

//uniform sampler2DRect texturemaskguide;
//uniform sampler2DRect imageMask;
uniform sampler2DRect texturefront;
uniform sampler2DRect textureback;

in vec2 texCoordVarying;

out vec4 outputColor;

void main()
{

    vec4 rTxt = texture(texturefront, texCoordVarying);
    vec4 mask = texture(textureback, texCoordVarying);
    
    vec4 color = vec4(0, 0, 0, 0);
   // color = mix(color, rTxt, mask.r);
   color = mix(mask, rTxt, rTxt.a);//overlay
    
    outputColor = color;

}
