#version 430

layout (location = 0) in vec3 vertPos;
layout (location = 1) in vec3 vertNormal;
out vec4 varyingColor;

struct PositionalLight
{	
   vec4 ambient;
   vec4 diffuse;
   vec4 specular;
   vec3 position;
};

struct Material
{	
   vec4 ambient;
   vec4 diffuse;
   vec4 specular;
   float shininess;
};

uniform vec4 globalAmbient;
uniform PositionalLight light;
uniform Material material;
uniform mat4 mv_matrix;
uniform mat4 proj_matrix;
uniform mat4 norm_matrix;

void main(void)
{	
   // Mock data for testing
   vec4 testLightAmbient = vec4(0.1, 0.1, 0.1, 1.0);
   vec4 testLightDiffuse = vec4(0.8, 0.8, 0.8, 1.0);
   vec4 testLightSpecular = vec4(1.0, 1.0, 1.0, 1.0);
   vec3 testLightPosition = vec3(10.0, 10.0, 10.0);

   vec4 testMaterialAmbient = vec4(0.2, 0.2, 0.2, 1.0);
   vec4 testMaterialDiffuse = vec4(0.5, 0.5, 0.5, 1.0);
   vec4 testMaterialSpecular = vec4(1.0, 1.0, 1.0, 1.0);
   float testMaterialShininess = 32.0;

   // convert vertex position to view space
   vec4 P = mv_matrix * vec4(vertPos, 1.0);

   // convert normal to view space
   vec3 N = normalize((norm_matrix * vec4(vertNormal, 0.0)).xyz);

   // calculate view-space light vector (from point to light)
   vec3 L = normalize(testLightPosition - P.xyz);

   // view vector is negative of view space position
   vec3 V = normalize(-P.xyz);

   // R is reflection of -L around the plane defined by N
   vec3 R = reflect(-L, N);

   // ambient, diffuse, and specular contributions
   vec3 ambient =
       ((globalAmbient * testMaterialAmbient)
       + (testLightAmbient * testMaterialAmbient)).xyz;

   vec3 diffuse =
       testLightDiffuse.xyz * testMaterialDiffuse.xyz
       * max(dot(N, L), 0.0);

   vec3 specular =
       pow(max(dot(R, V), 0.0f), testMaterialShininess)
       * testMaterialSpecular.xyz * testLightSpecular.xyz;

   // send the color output to the fragment shader
   varyingColor = vec4((ambient + diffuse + specular), 1.0);

   // send the position to the fragment shader, as before
   gl_Position = proj_matrix * mv_matrix * vec4(vertPos, 1.0);
}
