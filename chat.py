from openai import OpenAI

client = OpenAI()

response = client.responses.create(
    input="are you AI?",
    model="gpt-4.1"
)

print(response.output_text)