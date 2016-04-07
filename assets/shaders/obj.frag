precision mediump float;
varying vec3 varyNormal;
varying vec3 varyN;
varying vec3 varyCameraPos;
varying mat4 varyCameraMVP;

uniform vec3 uAmbientColor;
uniform vec3 uDiffuseColor;
uniform vec3 uSpecularColor;
uniform float uTransparent;
uniform float uSpecularHighlight;

void main()
{
	highp vec3 L  = (varyCameraMVP * vec4(0.0, 0.0, 2.0, 1.0)).xyz; /*Light Position*/
	highp vec3 N  = normalize(varyNormal);
	highp vec3 directionLight  = normalize(L-varyN);
	highp vec3 directionCamera = normalize(varyCameraPos-varyN);
	highp vec3 R  = normalize(reflect(directionLight, N));

	highp float intensity = 1.5;

	highp float df = max(0.0, dot(directionLight, N));
	highp float sf = 0.0;
	if(df > 0.0 && uSpecularHighlight > 0.0)
		sf = pow(max(0.0, dot(R, directionCamera)), uSpecularHighlight);

	highp float distance = length(L-varyN);

	highp vec3 Ip  = (uAmbientColor * uDiffuseColor + uDiffuseColor * df + uSpecularColor * sf)/pow(distance, 2.0)*intensity;;

	gl_FragColor = vec4(Ip, uTransparent);
};
