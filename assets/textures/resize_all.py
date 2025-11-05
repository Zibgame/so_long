from PIL import Image
import os
import re

TARGET_SIZE = (42, 42)
SIZE_LABEL = f"{TARGET_SIZE[0]}x{TARGET_SIZE[1]}"

for root, _, files in os.walk('.'):
    for file in files:
        if file.endswith('.png'):
            path = os.path.join(root, file)
            try:
                img = Image.open(path)
                img = img.resize(TARGET_SIZE, Image.LANCZOS)
                img.save(path)

                # Renommer le fichier s’il contient une taille
                new_name = re.sub(r'\d+x\d+', SIZE_LABEL, file)
                new_path = os.path.join(root, new_name)

                # Si le nom change, on renomme le fichier
                if new_path != path:
                    os.rename(path, new_path)

                print(f"✅ Resized and renamed: {new_name}")

            except Exception as e:
                print(f"❌ Error resizing {path}: {e}")

