attribute vec3 vPosition;
attribute vec3 vNormal;
varying   vec3 varyNormal;
varying   vec3 varyN;
varying   vec3 varyCameraPos;
varying   mat4 varyCameraMVP;

uniform mat4 uMVP;
uniform mat4 uTransformationMVP;
uniform mat4 uInverseMVP;
uniform mat4 uCameraMVP;
uniform mat4 uInverseCameraMVP;
uniform mat4 uTransposeInverseMVP;

void main()
{
	gl_Position   = uMVP * vec4(vPosition, 1.0);

	varyNormal    = (uTransposeInverseMVP*vec4(vNormal, 0.0)).xyz;
	varyN         = gl_Position.xyz;
	varyCameraPos = (-uInverseCameraMVP*uTransformationMVP*vec4(vPosition, 1.0)).xyz;
	varyCameraMVP = uCameraMVP;
};
