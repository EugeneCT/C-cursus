#include "Serializer.hpp"

int main(void)
{

	Data *data = new Data;
	data->name = "Eugene";
    data->address = "99999 Earth";
	data->age = 42;

	uintptr_t raw = Serializer::serialize(data);
    std::cout << raw<< std::endl;
	Data *serialized = Serializer::deserialize(raw);
	std::cout << serialized->name << std::endl;
    std::cout << serialized->address << std::endl;
	std::cout << serialized->age << std::endl;

	delete data;
	return (0);
}