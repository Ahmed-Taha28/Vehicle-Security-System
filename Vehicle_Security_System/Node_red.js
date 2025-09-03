// Node-RED Function Node Configuration
// Name: function 2

// Execution Triggers:
// Setup - Runs when node is started
// On Start - Runs when flow is deployed
// On Message - Runs when message is received
// On Stop - Runs when node is stopped

// On Message Event Handler:
var payload = msg.payload; // Extract payload from incoming message

// Log first 7 characters of payload for debugging
node.warn(payload.substr(0,7));

// Check if payload starts with "Invalid"
if (payload.substr(0, 7) == "Invalid") {
    node.warn("WORKSSS"); // Log success message
    return msg; // Return the message to output
} else {
    // Optional: Uncomment for debugging non-matching messages
    // node.warn("NOTWORKING");
    
    // Note: No return statement - message will not be forwarded
}