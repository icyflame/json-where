# json-where

> Where are you inside a JSON file?

![screenshot][13]

## Contents

- [Usage][4]
- [Compile from source][1]
- [Credits][8]
- [License][9]

## Usage

`json-where` can be used from the command line. You can also set it up to run
using a keybinding inside the editor of your choice.

### From the Command Line

```sh
# json-where file-name line column
$ json-where test.json 250  14
.[5].tags[3]
```

### Inside `vim`

You can also invoke `json-where` from `vim`. Once you build `json-where` and put
the executable in your `PATH`, you can use this function to invoke it based on
your cursor position.

```vim
function JsonWhere()
    if executable("json-where") == 0
        return 'ERROR: json-where not found in PATH'
    endif

    let cursor = getcurpos()
    let lnum = cursor[1]
    let colnum = cursor[2]

    let cmd_list = [ ]
    let cmd_list += [ 'json-where' ]
    let cmd_list += [ expand('%:p') ]
    let cmd_list += [ lnum ]
    let cmd_list += [ colnum ]

    let cmd = join(cmd_list, ' ')
    let json_where_output = systemlist(cmd)

    if len(json_where_output) > 0
        return json_where_output[len(json_where_output)-1]
    else
        return 'ERROR: json-where output is invalid'
    endif
endfunction
```

You can attach a keybinding to this function in normal mode:

```vim
nmap <leader>jw :echo JsonWhere()<cr>
```

**Note:** For best results, call JsonWhere with the cursor on the first
character in the JSON key or value.

## Compile from source

json-where is a C++ program that uses C++11 features. It can be compiled and
installed using the standard GNU program compile process:

```sh
$ ./configure
$ make
$ sudo make install
```

By default, these commands will install the executable `json-where` to your
computer's `/usr/local/bin/` folder. You can change the prefix by running the
configure script with the `--prefix` option. More details about autoconf can be
found on the [autoconf manual][2].

The configure script and other related files were generated using the
[`autogen.sh`][3] script.

## Credits

- [`giacomodrago/minijson_reader`][10]

## License

`minijson_reader`'s LICENSE is included [here][11] and appended to the
[LICENSE][12] notice at the root of this repository.

Everything else in this repository is licensed under the MIT license.

Copyright (C) 2019 Siddharth Kannan <mail@siddharthkannan.in>

[1]: #compile-from-source
[2]: https://www.gnu.org/savannah-checkouts/gnu/autoconf/manual/autoconf-2.69/autoconf.html#Installation-Names
[3]: ./autogen.sh
[4]: #usage
[5]: #from-the-command-line
[6]: inside-vim
[7]: #install
[8]: #credits
[9]: #license
[10]: https://github.com/giacomodrago/minijson_reader
[11]: ./src/nested_json/minijson/LICENSE.txt
[12]: ./LICENSE
[13]: ./img/screenshot.png
