// The length of data in seconds used for estimating HR
#define SAMPLE_TIME 5
// The length of new data in seconds that is averaged w/ old data to find HR
#define NEW_DATA_SAMPLE_TIME 1
// Sampling rate
#define FS 100
#define BUFFER_SIZE NEW_DATA_SAMPLE_TIME * FS

/**
 * Defines the PCB struct
 */
struct linked_buffer {
	unsigned int buffer[BUFFER_SIZE]; // Each buffer is the number of samples in a new data sample
    struct linked_buffer *next; /* Next buffer in the list */
};
typedef struct linked_buffer;



int
main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	unsigned int data[SAMPLE_TIME * FS];
	unsigned int NUM_BUFFERS = ceil(SAMPLE_TIME/NEW_DATA_SAMPLE_TIME);
	// Buffers for processing data
	struct circular_buffers[NUM_BUFFERS];
	struct *linked_buffer_head, *linked_buffer_tail;
	struct *current_linked_buffer;
	{
		/* data */
	};

	// Builds the circular linked list
	int i;
	for(i = 0; i < NUM_BUFFERS; i++){
		circular_buffers[i].next = &circular_buffers[(i+1) % NUM_BUFFERS];
	}
	// Initializes the head and the tail of the buffers
	linked_buffer_head = circular_buffers;
	linked_buffer_tail = &circular_buffers[NUM_BUFFERS - 1];
	
	current_linked_buffer = linked_buffer_head->buffer;

	// Generates data to test circular linked list of buffers
	unsigned int data = 0, i = 0;
	unsigned int num_empty_buffers_left = NUM_BUFFERS;
	// Indicates whether all the buffers are full - used for init
	unsigned int buffer_full = 0;
	while(1) {
		data = (data + 1) % UINT_MAX;

		if (num_empty_buffers_left == 0) {
			BUFFERS_FULL = 1;
		}
		(current_linked_buffer->buffer)[i] = data; 
		

		// Checks if we are at the end of the buffer
		if (i == BUFFER_SIZE - 1) {
			/*
			 * Ensures that all the empty buffers are filled before beginning to recycle buffers(starting at the head)
			 * Also ensures that we are not looking at empty data
			 */
			if (BUFFERS_FULL) {
				// Pops buffer at the head(it has the oldest data) and inserts it at the end
				current_linked_buffer = PopHead();
				InsertEndTail(current_linked_buffer);
			}
			// Hops to the next buffer
			else 
				current_linked_buffer = current_linked_buffer->next;
		}
		i = (i + 1) % BUFFER_SIZE;
	}

}

/**
 * Pops the head of the buffer list
 */
static linked_buffer *PopHead() {

	// Pops the head of the buffer list
	struct linked_buffer *popped_buffer = linked_buffer_head;

	if(linked_buffer_head == NULL) {
		fprintf(stderr, "%s\n", "Error no more buffers");
		Exit(0);
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
static void InsertEndTail(linked_buffer *buffer) {

	TracePrintf(5,"INSERTING TO THE END OF Linked buffer \n");

	TracePrintf(5, "Buffer next NEXT: %p\n", buffer->next);
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