attribute vec3 vPosition;
attribute vec2 vTextureCoord;
uniform mat4 uMVP;

varying vec2 vary_textureCoord;

void main()
{
	gl_Position = uMVP * vec4(vPosition, 1.0);
	vary_textureCoord = vTextureCoord;
};
