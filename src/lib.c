/**
 * @file lib.c
 * @brief Файл з реалізацією функцій оперування тваринами
 *
 * @author Davydov V.
 * @date 14-apr-2020
 * @version 1.3
 */

#include "lib.h"

char *get_animal_type_name(enum animal_type type)
{
	char *result;
	switch (type) {
	case CAT:
		result = "Cat";
		break;
	case DOG:
		result = "Dog";
		break;
	case COW:
		result = "Cow";
		break;
	case PIG:
		result = "Pig";
		break;
	case HUMAN:
	    result = "Human";
	    break;
	default:
		result = "N/A";
	}
	return result;
}

char *get_sound_type(enum sound_type type) {
    char *result;
    switch (type) {
    case catSound:
        result = "meow";
        break;
    case dogSound:
        result = "woof";
        break;
    case cowSound:
        result = "moo";
        break;
    case pigSound:
        result = "oink";
        break;
     case humanSound:
        result = "goodbye";
        break;
    default:
        result = "N/A";
    }
    return result;
}

void generate_animal(struct animal *entity)
{
    entity->sound = (unsigned  int)rand() % soundTypeCount;
	entity->height = (unsigned int)rand() % INT8_MAX;
	entity->weight = (unsigned int)rand() % INT8_MAX;
	entity->type = (unsigned int)rand() % ANIMAL_TYPE_COUNT;
}

void show_animals(struct animal animals[], unsigned int count)
{
	for (unsigned int i = 0; i < count; i++) {
		printf("Інформація про тварину №%02u: ", i + 1);
		printf("%s: зріст = %u см, маса = %u гр. \n",
		       get_animal_type_name(animals[i].type), animals[i].height,
		       animals[i].weight);
		printf("Звук тварини: %s \n", get_sound_type(animals[i].sound));
	}
}
