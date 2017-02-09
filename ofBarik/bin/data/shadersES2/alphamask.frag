precision highp float;

uniform sampler2D texturemaskguide;
uniform sampler2D imageMask;

varying vec2 texCoordVarying;

void main()
{

    vec4 rTxt = texture2D(texturemaskguide, texCoordVarying);
    vec4 mask = texture2D(imageMask, texCoordVarying);
    
    vec4 color = vec4(0, 0, 0, 0);
    color = mix(color, rTxt, mask.a);
    gl_FragColor = color;


}
