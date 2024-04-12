const amqplib = require("amqplib");

async function sendMessage() {
  try {
    const connection = await amqplib.connect("amqp://localhost");
    const channel = await connection.createChannel();
    const queue = "messages";
    const message = "Hej H5!";

    await channel.assertQueue(queue, { durable: true }); // Set durable to true

    channel.sendToQueue(queue, Buffer.from(message), { persistent: true }); // Set persistent to true
    console.log("Message sent successfully");

    // Delay the process exit to ensure the message is sent
    setTimeout(async function () {
      await channel.close();
      await connection.close();
      console.log("Connection closed");
      process.exit(0);
    }, 500); // Adjust the delay as needed
  } catch (error) {
    console.error("Error sending message:", error);
  }
}

sendMessage().catch(console.error);
