precision mediump float;
varying vec2 vary_textureCoord;

uniform sampler2D uTexture;

void main()
{
	gl_FragColor = texture2D(uTexture, vary_textureCoord);
};
