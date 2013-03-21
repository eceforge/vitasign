#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
// The length of data in seconds used for estimating HR
#define SAMPLE_TIME 5
// The length of new data in seconds that is averaged w/ old data to find HR
#define NEW_DATA_SAMPLE_TIME 1
// Sampling rate
#define FS 10
#define BUFFER_SIZE NEW_DATA_SAMPLE_TIME * FS
#define CEIL(VARIABLE) ( (VARIABLE - (int)VARIABLE)==0 ? (int)VARIABLE : (int)VARIABLE+1 )
#define NUM_BUFFERS CEIL(SAMPLE_TIME/NEW_DATA_SAMPLE_TIME)
/**
 * Defines the PCB struct
 */
struct linked_buffer {
	unsigned int buffer[BUFFER_SIZE]; // Each buffer is the number of samples in a new data sample
    struct linked_buffer *next; /* Next buffer in the list */
};
typedef struct linked_buffer Linked_Buffer;

Linked_Buffer *linked_buffer_head, *linked_buffer_tail;

// Buffers for processing data
Linked_Buffer circular_buffers[NUM_BUFFERS];
Linked_Buffer *current_linked_buffer;
unsigned int data_out[SAMPLE_TIME * FS];

/**
 * Function prototypes
 * @return
 */
static void printCircularLinkedBuffer(Linked_Buffer *head, Linked_Buffer *tail);
static void copyDataOut(Linked_Buffer *head, unsigned int *buf);
static void printData(unsigned int *data);

int
main(int argc, char **argv)
{
	// Generates data to test circular linked list of buffers
	unsigned int data = 0, how_many_times = 0;
	unsigned int num_empty_buffers_left = NUM_BUFFERS, buffers_full = 0;
	// unsigned int data[SAMPLE_TIME * FS];
	// unsigned int num_buffers = ceil(SAMPLE_TIME/NEW_DATA_SAMPLE_TIME);

	setbuf(stderr, NULL);

	// Builds the circular linked list
	int i;
	for(i = 0; i < NUM_BUFFERS; i++){
		circular_buffers[i].next = &circular_buffers[(i+1) % (NUM_BUFFERS)];
	}
	// Initializes the head and the tail of the buffers
	linked_buffer_head = circular_buffers;
	linked_buffer_tail = &circular_buffers[NUM_BUFFERS - 1];
	
	current_linked_buffer = linked_buffer_head;

	// Resets i
	i = 0;
	// Indicates whether all the buffers are full - used for init
	// unsigned int buffers_full = 0;
	while(how_many_times != 60) {
		data = (data + 1) % UINT_MAX;
		if (num_empty_buffers_left == 0)
			buffers_full = 1;
		// fprintf(stderr, "Filling buffer @ index %i Buffer size is %u\n",  i, BUFFER_SIZE);
		(current_linked_buffer->buffer)[i] = data; 
		
		// Checks if we are at the end of the buffer
		if (i == BUFFER_SIZE - 1) {
			printf("%s\n", "Hopping onto the next buffer...");
			current_linked_buffer = current_linked_buffer->next;
			printCircularLinkedBuffer(linked_buffer_head, linked_buffer_tail);

			// Updates the buffer full
			if(!buffers_full)
				num_empty_buffers_left--;
			// Copies the data out of the linked buffer
			else {
				copyDataOut(current_linked_buffer, data_out);
				printData(data_out);
			}
		}
		i = (i + 1) % (BUFFER_SIZE);
		how_many_times++;
	}
	return 0;

}


/**
 * Prints all the buffers in the circularly linked list of buffers
 * @param head
 * @param tail
 */
static void copyDataOut(Linked_Buffer *head, unsigned int *buf) {
	printf("%s\n", "Copying the circular buffer our to the buffer" );
	Linked_Buffer current_linked_buffer;
	unsigned int i, linked_buffer;

	/**
	 * Copies all the data out of the buffers in the linked list to buf
	 */
	for (linked_buffer=1; linked_buffer <= NUM_BUFFERS; linked_buffer++) {
		current_linked_buffer = head[linked_buffer];
		// Copies all the data out of the buffer
		for(i=0; i < BUFFER_SIZE; i+=1)  {
			buf[i * linked_buffer] = (current_linked_buffer.buffer)[i];
		}
		// current_linked_buffer = current_linked_buffer->next;
	}
	
}

/**
 * Prints the data out array
 */
static void printData(unsigned int *data) {
	unsigned int i;
	printf("Printing data out\n");
	for(i = 0; i < BUFFER_SIZE; i+=1)  {
		printf("%u ", data[i]);
	}
}

/**
 * Prints all the buffers in the circularly linked list of buffers
 * @param head
 * @param tail
 */
static void printCircularLinkedBuffer(Linked_Buffer *head, Linked_Buffer *tail) {
	printf("%s\n", "Printing the circular buffer" );
	Linked_Buffer *current_linked_buffer = head;
	unsigned int i;
	/**
	 * Prints each buffer
	 */
	do {
		for(i = 0; i < BUFFER_SIZE; i+=1)  {
			printf("%u ", (current_linked_buffer->buffer)[i]);
		}
		current_linked_buffer = current_linked_buffer->next;
	}
	while(current_linked_buffer != head);
}
