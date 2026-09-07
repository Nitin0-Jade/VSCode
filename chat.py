from openai import OpenAI

client = OpenAI()

user_prompt= input("Enter your prompt: ")
system_prompt= "Limit to one word"

response = client.responses.create(
    input=user_prompt,
    instructions=system_prompt,
    model="gpt-4.1"
)

print(response.output_text)