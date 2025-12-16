#include "Serializer.hpp"

int main() {
	Data data;
	data.x = 214748364;
	data.y = 24;
	data.z = 'a';
	data.w = false;

	std::cout << "Unserialized data: " << data.x << ", " << data.y << ", " << data.z << ", " << data.w << std::endl;

	std::cout << "a : " << &data << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized data: " << raw << std::endl;
	raw += 4;

	Data *deserializedData = static_cast<Data *>(Serializer::deserialize(raw));
	// std::cout << "Deserialized data: " << deserializedData << ", " << deserializedData->y << ", " << deserializedData->z << ", " << deserializedData->w << std::endl;
	// deserializedData = deserializedData - 2;
	std::cout << "Shifted x: " << deserializedData->x << std::endl;
	deserializedData += 3;
	std::cout << "Shifted x: " << (char)deserializedData->x << std::endl;
	return 0;
}
