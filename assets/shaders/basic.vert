attribute vec3 vPosition;
uniform mat4 mvp;

void main()
{
	gl_Position = mvp * vec4(vPosition, 1.0);
};
