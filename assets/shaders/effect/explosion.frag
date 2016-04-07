precision mediump float;

uniform vec4  uBaseColor;
varying float varyIntensity;

void main()
{
	vec4 atenuation;
	for(int i=0; i < 4; i=i+1)
	{
		atenuation[i] = pow(uBaseColor[i], varyIntensity);
	}
	gl_FragColor = atenuation;
};
