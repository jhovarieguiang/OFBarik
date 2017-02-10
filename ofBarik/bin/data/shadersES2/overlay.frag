precision highp float;

//uniform sampler2D texturemaskguide;
//uniform sampler2D imageMask;
uniform sampler2D texturefront;
uniform sampler2D textureback;

varying vec2 texCoordVarying;

void main()
{

    vec4 rTxt = texture2D(texturefront, texCoordVarying);
    vec4 mask = texture2D(textureback, texCoordVarying);
    
    vec4 color = vec4(0, 0, 0, 0);
    // color = mix(color, rTxt, mask.a);
     color = mix(mask, rTxt, rTxt.a);//overlay
    gl_FragColor = color;


}
