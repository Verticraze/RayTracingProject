#include<iostream>
#include<ray.h>
#include"vec3.h"
#include"color.h"

double hit_sphere(const point3& center, double radius , const ray& r)
{
	vec3 oc = center - r.origin();
	auto a = dot(r.direction(),r.direction());
	auto b = -2.0 * dot(r.direction(),oc);
	auto c = dot(oc,oc) - radius * radius;
	auto discriminant = b*b - 4*a*c;
	if(discriminant < 0){
		return -1.0;
	} else {
		return (-b - std::sqrt(discriminant)/2.0*a);
	}
}

color ray_color(const ray& r){
	auto t = hit_sphere(point3(0,0,-1),0.5,r);
	if(t>0.0) {    
		vec3 N = unit_vector(r.at(t) - vec3(0,0,-1));
		return 0.5* color(N.x()+1,N.y()+1,N.z()+1);
	}
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main() {
	auto aspect_ratio = 4.0/3.0;

	int image_width = 400;
	int image_height = int( image_width / aspect_ratio );
	image_height = (image_height < 1) ? 1 : image_height;

	auto focal_length = 1.0;
	auto viewport_height = 2.0;
	auto viewport_width = viewport_height * (double(image_width)/ image_height);
	auto center = point3(0,0,0);

	auto viewport_u = vec3(viewport_width,0,0);
	auto viewport_v = vec3(0,-viewport_height,0);

	auto pixel_delta_u = viewport_u / image_width;
	auto pixel_delta_v = viewport_v / image_height;

	auto viewport_top_left = center - vec3(0,0,focal_length) - viewport_u/2 - viewport_v/2;
	auto origin = viewport_top_left + 0.5 * (pixel_delta_u + pixel_delta_v);

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; j++)
	{
		std::clog << "\rScan lines remaining: " << (image_height - j) << ' ' << std::flush;
		for (int i = 0; i < image_width; i++)
		{
			auto pixel_center = origin + (i*pixel_delta_u) + (j * pixel_delta_v);
			auto ray_dir = pixel_center - center;
			ray r (center,ray_dir);
			color pixel_color = ray_color(r);
			write_color(std::cout,pixel_color);
		}
	}

	std::clog << "\r Done.              \n";
	return 0;
}
