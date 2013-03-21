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

/**
 * Defines the PCB struct
 */
struct linked_buffer {
	unsigned int buffer[BUFFER_SIZE]; // Each buffer is the number of samples in a new data sample
    struct linked_buffer *next; /* Next buffer in the list */
};
typedef struct linked_buffer Linked_Buffer;

Linked_Buffer *linked_buffer_head, *linked_buffer_tail;
/**
 * Function prototypes
 * @return
 */
static Linked_Buffer *PopHead();
static void InsertEndTail(Linked_Buffer *buffer);
static void printCircularLinkedBuffer(Linked_Buffer *head, Linked_Buffer *tail);
int
main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	// unsigned int data[SAMPLE_TIME * FS];
	unsigned int num_buffers = ceil(SAMPLE_TIME/NEW_DATA_SAMPLE_TIME);
	// Buffers for processing data
	Linked_Buffer circular_buffers[num_buffers];
	Linked_Buffer *current_linked_buffer;

	// Builds the circular linked list
	int i;
	for(i = 0; i < num_buffers; i++){
		circular_buffers[i].next = &circular_buffers[(i+1) % num_buffers];
	}
	// Initializes the head and the tail of the buffers
	linked_buffer_head = circular_buffers;
	linked_buffer_tail = &circular_buffers[num_buffers - 1];
	
	current_linked_buffer = linked_buffer_head;

	// Generates data to test circular linked list of buffers
	unsigned int data = 0, how_many_times = 0; i = 0;
	unsigned int num_empty_buffers_left = num_buffers;
	// Indicates whether all the buffers are full - used for init
	unsigned int buffers_full = 0;
	while(how_many_times != 60) {
		data = (data + 1) % UINT_MAX;

		if (num_empty_buffers_left == 0) {
			buffers_full = 1;
		}
		// fprintf(stderr, "Filling buffer @ index %i Buffer size is %u\n",  i, BUFFER_SIZE);
		(current_linked_buffer->buffer)[i] = data; 
		

		// Checks if we are at the end of the buffer
		if (i == BUFFER_SIZE - 1) {
			/*
			 * Ensures that all the empty buffers are filled before beginning to recycle buffers(starting at the head)
			 * Also ensures that we are not looking at empty data
			 */
			if (buffers_full) {
				printCircularLinkedBuffer(linked_buffer_head, linked_buffer_tail);
				fprintf(stderr, "%s\n", "Buffer is full swapping buffer..");
				// Pops buffer at the head(it has the oldest data) and inserts it at the end
				current_linked_buffer = PopHead();
				InsertEndTail(current_linked_buffer);
				printCircularLinkedBuffer(linked_buffer_head, linked_buffer_tail);
			}
			// Hops to the next buffer
			else  {
				fprintf(stderr, "%s\n", "Hopping onto the next buffer...");
				current_linked_buffer = current_linked_buffer->next;
				num_empty_buffers_left--;
				printCircularLinkedBuffer(linked_buffer_head, linked_buffer_tail);
			}
		}
		i = (i + 1) % (BUFFER_SIZE);
		how_many_times++;
	}
	return 0;

}

/**
 * Pops the head of the buffer list
 */
static Linked_Buffer *PopHead() {

	// Pops the head of the buffer list
	Linked_Buffer *popped_buffer = linked_buffer_head;

	if(linked_buffer_head == NULL) {
		fprintf(stderr, "%s\n", "Error no more buffers");
	}
	else if(linked_buffer_head == linked_buffer_tail) {
		fprintf(stderr, "%s\n", "Reached the end of the list. This should never happen");
		linked_buffer_head = NULL;
		linked_buffer_tail = NULL;
		return popped_buffer;
	}

	// Set the one after the previous head of the list to be the new head
	linked_buffer_head = popped_buffer->next;
	// Circularly links the list
	linked_buffer_tail->next = linked_buffer_head;


	// if(linked_buffer_head != NULL) {
	// 	pcbs_ready->prev = NULL;
	// }
	// else {
	// 	pcbs_ready_tail = NULL;
	// }

	return popped_buffer;

}
/**
 * Inserts a buffer at the end of the list
 * @param pcb1 [description]
 */
static void InsertEndTail(Linked_Buffer *buffer) {

	fprintf(stderr,"INSERTING TO THE END OF Linked buffer \n");

	fprintf(stderr, "Buffer next NEXT: %p\n", buffer->next);
	// NULL CHECKS
	if (buffer == NULL) {
		fprintf(stderr, "%s\n", "WHAT! Element of insert is null" );
	}
	else if(linked_buffer_tail == NULL) {
		fprintf(stderr, "%s\n", "WHAT! tail is null" );
	}
	else {
		linked_buffer_tail->next = buffer;
		// Inserting at the tail next yet.
		buffer->next = linked_buffer_head;
		// updates the tail
		linked_buffer_tail = buffer;
	}	
	
}
/**
 * Prints all the buffers in the circularly linked list of buffers
 * @param head
 * @param tail
 */
static void printCircularLinkedBuffer(Linked_Buffer *head, Linked_Buffer *tail) {
	fprintf(stderr, "%s\n", "Printing the circular buffer" );
	Linked_Buffer *current_linked_buffer = head;
	unsigned int i;
	/**
	 * Prints each buffer
	 */
	do {

		for(i=0; i < BUFFER_SIZE; i+=1)  {
			fprintf(stderr, "Data is %u\n", (current_linked_buffer->buffer)[i]);
		}
		current_linked_buffer = current_linked_buffer->next;
	}
	while(current_linked_buffer != head);
}
/**
 * Pushes a buffer at the top of the list
 * @param pcb1 [description]
 */
// static void pushBuffer(linked_buffer *buffer) {

// 	TracePrintf(5,"INSERTING TO THE END OF READY\n");
// 	TracePrintf(5, "Buffer next NEXT: %p\n", buffer->next);
// 	if (buffer == NULL) {
// 		fprintf(stderr, "%s\n", "WHAT! Element ot insert is null" );
// 	}
// 	// If the List is currently empty, this entry is both the head and tail
// 	else if(linked_buffer_head == NULL) {
// 		fprintf(stderr, "%s\n", "WHAT! tail is null" );
// 		/*pcb1->prev = NULL;
// 		pcbs_ready = pcb1;
// 		pcbs_ready_tail = pcb1;*/
// 	}
// 	// Otherwise, just the tail and the previous tail is its previous
// 	else {
// 		// Inserting at the head, so no next yet.
// 		buffer->next = linked_buffer_head;
// 		// Updates the head
// 		linked_buffer_head = buffer;
// 		// Updates the tail to point to the head
// 		linked_buffer_tail->next = linked_buffer_head;
// 	}	
	
// }