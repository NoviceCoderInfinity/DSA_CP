# FIX REQUIRED
#---------------------------------------------------------------------

def parse_and_format_problem(problem_text):
    # List of keywords that denote the start of new sections
    keywords = ["Easy", "Medium", "Hard", "Example", "Constraints"]
    
    # Initialize variables for storing sections
    problem_id = ""
    title = ""
    difficulty = ""
    topics = ""
    problem_description = ""
    examples = []
    constraints = ""
    
    # Flags to keep track of which section we're in
    current_section = "title"

    # Process the text word by word
    words = problem_text.split()
    i = 0
    while i < len(words):
        word = words[i]
        
        # Determine section by checking keywords
        if word in ["Easy", "Medium", "Hard"]:
            difficulty = word
            current_section = "topics"  # After difficulty, expect topics or problem description
            i += 1
            continue
        
        elif word.startswith("Example"):
            example_text = ' '.join(words[i:]).split("Constraints")[0].strip()
            examples.append(example_text)
            current_section = "constraints"
            break
        
        elif word == "Constraints:":
            constraints = ' '.join(words[i:])
            break

        # Accumulate text based on current section
        if current_section == "title":
            problem_id += word + " "
        elif current_section == "topics":
            topics += word + " "
        elif current_section == "problem_description":
            problem_description += word + " "

        i += 1

    # Clean up extracted data
    problem_id = problem_id.strip()
    title = ' '.join(problem_id.split()[1:])
    problem_id = problem_id.split()[0]
    topics = topics.replace("Topics", "").strip()
    problem_description = problem_description.strip()

    # Format the output
    formatted_output = f"### {problem_id}. {title}\n"
    formatted_output += f"**Difficulty:** {difficulty}\n"
    formatted_output += f"**Topics:** {topics if topics else 'None provided'}\n\n"
    formatted_output += "### Problem Description\n\n"
    formatted_output += problem_description + '\n\n'
    
    for i, example in enumerate(examples):
        formatted_output += f"**Example {i + 1}:**\n\n"
        formatted_output += f"```text\n{example.strip()}\n```\n\n"

    if constraints:
        formatted_output += "### Constraints\n\n"
        formatted_output += constraints.strip() + '\n'
    
    return formatted_output


def read_problem_from_file(file_path):
    with open(file_path, 'r') as file:
        problem_text = file.read()
    return problem_text


def write_formatted_problem_to_file(file_path, formatted_problem):
    with open(file_path, 'w') as file:
        file.write(formatted_problem)


# File paths
input_file_path = 'problem_to_format.txt'
output_file_path = 'formatted_problem.txt'

# Reading, formatting, and writing
problem_text = read_problem_from_file(input_file_path)
formatted_problem = parse_and_format_problem(problem_text)
write_formatted_problem_to_file(output_file_path, formatted_problem)

print(f"Formatted problem has been written to {output_file_path}")

