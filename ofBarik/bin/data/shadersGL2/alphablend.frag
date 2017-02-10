#version 120
//this is currently works

uniform float mixturePercent;
uniform sampler2DRect texturefront;
uniform sampler2DRect textureback;

varying vec2 texCoordVarying;

void main()
{
    vec4 rTxt = texture2DRect(texturefront, texCoordVarying);
    vec4 mask = texture2DRect(textureback, texCoordVarying);
    
    vec4 color = vec4(0, 0, 0, 0);
   // color = mix(mask, rTxt, rTxt.a);//overlay

   // float mixturePercent = .5;
	color = vec4(mix(mask.rgb, rTxt.rgb, rTxt.a * mixturePercent), mask.a);
    
    gl_FragColor = color;
}
