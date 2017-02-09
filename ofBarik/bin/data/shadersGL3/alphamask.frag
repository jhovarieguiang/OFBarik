#version 150

uniform sampler2DRect texturemaskguide;
uniform sampler2DRect imageMask;

in vec2 texCoordVarying;

out vec4 outputColor;

void main()
{

    vec4 rTxt = texture(texturemaskguide, texCoordVarying);
    vec4 mask = texture(imageMask, texCoordVarying);
    
    vec4 color = vec4(0, 0, 0, 0);
    color = mix(color, rTxt, mask.r);
    
    outputColor = color;

}
