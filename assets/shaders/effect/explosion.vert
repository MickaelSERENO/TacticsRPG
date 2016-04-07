attribute vec3 vPosition;
varying float varyIntensity;

uniform mat4 uMVP;
uniform float uIntensity;

void main()
{
	gl_Position   = uMVP * vec4(vPosition, 1.0);
	gl_PointSize  = 7.0;
	varyIntensity = uIntensity;
};
