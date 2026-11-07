
What do we want?
- good interaction with DBC
    - abstraction (messages, signals, offset, factor, signal typing, FD functionality will break bus so prob not)
- relatively easy for user to use
    - send
    - receive
    - dma? prob not necessary


What should usage look like?

definition:
each signal is a byte slice of a message
message {
    message id (uint16, 11 bits max for standard)
    number of signals
    &signal (to allow dynamic number of signals)
}

signal {
    start bit
    bit length
    type
    data
    factor
    offset
}



how to reg a message? signal?

msg = new_msg(id, numsig, sigs[])

sig = new_signal(type, start, length, factor, offset)
update_sig(sig, (void*)data)

send_msg(msg);


how to recieve message
register_mesgae(message, callback func)
- when you get a matching message, call this func on it
message* = register_return_message(message)
- mallocs memory for message which is updated whenever that message is received

returns value of signal type = parse_signal(message, signal)