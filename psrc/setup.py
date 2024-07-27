from setuptools import setup, find_packages

setup(
    name='psrc',
    version='0.1',
    packages=find_packages(),    # Automatically find packages in the current directory
    install_requires=[           # List of dependencies (if any)
        # 'some_package',
    ],
    entry_points={               # Entry points for command-line scripts (if any)
        'console_scripts': [
            # 'your_command=your_module:main_function',
        ],
    },
)
