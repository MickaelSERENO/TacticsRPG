precision mediump float;
varying vec2 vary_textureCoord;

uniform sampler2D uTexture;
uniform float uOpacity;

void main()
{
	gl_FragColor = texture2D(uTexture, vary_textureCoord);
	if(uOpacity > 0.0)
		gl_FragColor.a = uOpacity;
};
