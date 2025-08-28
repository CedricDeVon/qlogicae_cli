
<#
Describe "[qlogicae_cli string] test suite" {
    BeforeAll {
        . $PSScriptRoot/imports.ps1

        $outputFile = ".qlogicae/cli/string-generate.txt"

        if (Test-Path $outputFile) {
            Remove-Item $outputFile
        }
    }

    AfterAll {
        if (Test-Path $outputFile) {
            Remove-Item $outputFile
        }
    }





    It "[qlogicae_cli string]: should be null or empty" {
        $testResult = qlogicae_cli string | Out-String        

        $testResult | Should -BeNullOrEmpty
    }

    It "[qlogicae_cli string --help]: should not be null or empty" {
        $testResult = qlogicae_cli string --help | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }
    




    It "[qlogicae_cli string generate]: generate instance(s) based on default parameters" {
        $testResult = qlogicae_cli string generate | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --help]: should not be null or empty" {
        $testResult = qlogicae_cli string generate --help | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }




    It "[qlogicae_cli string generate --length='']: should terminate" {
        $testResult = qlogicae_cli string generate --length='' | Out-String
        
        $testResult | Should -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='-10']: should terminate" {
        $testResult = qlogicae_cli string generate --length='-10' | Out-String
        
        $testResult | Should -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='-1']: should terminate" {
        $testResult = qlogicae_cli string generate --length='-1' | Out-String
        
        $testResult | Should -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='0']: should terminate" {
        $testResult = qlogicae_cli string generate --length='0' | Out-String
        
        $testResult | Should -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='1']: should generate 1 instance(s)" {
        $testResult = qlogicae_cli string generate --length='1' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='10']: should generate 10 instance(s)" {
        $testResult = qlogicae_cli string generate --length='10' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }




    It "[qlogicae_cli string generate --length='10' --count='']: should terminate" {
        $testResult = qlogicae_cli string generate --length='10' --count='' | Out-String
        
        $testResult | Should -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='10' --count='-10']: should terminate" {
        $testResult = qlogicae_cli string generate --length='10' --count='-10' | Out-String
        
        $testResult | Should -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='10' --count='-1']: should terminate" {
        $testResult = qlogicae_cli string generate --length='10' --count='-1' | Out-String
        
        $testResult | Should -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='10' --count='0']: should terminate" {
        $testResult = qlogicae_cli string generate --length='10' --count='0' | Out-String
        
        $testResult | Should -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='10' --count='1']: should generate 10 instance(s) with 1 character length" {
        $testResult = qlogicae_cli string generate --length='10' --count='1' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='10' --count='10']: should generate 10 instance(s) with 10 character length" {
        $testResult = qlogicae_cli string generate --length='10' --count='10' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }




    It "[qlogicae_cli string generate --length='10' --count='10' --character-set='']: should terminate" {
        $testResult = qlogicae_cli string generate --length='10' --count='10' --character-set='' | Out-String
        
        $testResult | Should -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='10' --count='10' --character-set='a']: should generate 10 instance(s) with character(s) 'a'" {
        $testResult = qlogicae_cli string generate --length='10' --count='10' --character-set='a' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='10' --count='10' --character-set='ab']: should generate 10 instance(s) with character(s) 'ab'" {
        $testResult = qlogicae_cli string generate --length='10' --count='10' --character-set='ab' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='10' --count='10' --character-set='aba']: should generate 10 instance(s) with character(s) 'ab'" {
        $testResult = qlogicae_cli string generate --length='10' --count='10' --character-set='aba' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='10' --count='10' --character-set='0123456789ABCDEF']: should generate 10 instance(s) with character(s) '0123456789ABCDEF'" {
        $testResult = qlogicae_cli string generate --length='10' --count='10' --character-set='0123456789ABCDEF' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }





    It "[qlogicae_cli string generate --length='10' --count='10' --character-set='0123456789ABCDEF' --is-verbose-logging-enabled='false']: should generate 10 instance(s) with character(s) '0123456789ABCDEF'" {
        $testResult = qlogicae_cli string generate --length='10' --count='10' --character-set='0123456789ABCDEF' --is-verbose-logging-enabled='false' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='10' --count='10' --character-set='0123456789ABCDEF' --is-verbose-logging-enabled='true']: should generate 10 instance(s) with character(s) '0123456789ABCDEF'" {
        $testResult = qlogicae_cli string generate --length='10' --count='10' --character-set='0123456789ABCDEF' --is-verbose-logging-enabled='true' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }





    It "[qlogicae_cli string generate --length='10' --count='10' --character-set='0123456789ABCDEF' --is-file-output-enabled='false']: should generate instance(s) on the console but not the file" {
        $testResult = qlogicae_cli string generate --length='10' --count='10' --character-set='0123456789ABCDEF' --is-file-output-enabled='false' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --length='10' --count='10' --character-set='0123456789ABCDEF' --is-file-output-enabled='true']: should generate instance(s) on the console and file" {
        $testResult = qlogicae_cli string generate --length='10' --count='10' --character-set='0123456789ABCDEF' --is-file-output-enabled='true' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty

        Test-Path $outputFile | Should -BeTrue
    }
}

    It "[qlogicae_cli string generate --count='-1']: should terminate" {
        $testResult = qlogicae_cli string generate --count='-1' | Out-String
        
        $testResult | Should -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --count='0']: should terminate" {
        $testResult = qlogicae_cli string generate --count='0' | Out-String
        
        $testResult | Should -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate]: should generate 1 string(s) on the console" {
        $testResult = qlogicae_cli string generate | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --count='10']: should generate 10 string(s) on the console" {
        $testResult = qlogicae_cli string generate --count='10' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --count='10' --is-file-output-enabled='false']: should generate 10 string(s) on the console but not the file" {
        $testResult = qlogicae_cli string generate --count='10' --is-file-output-enabled='false' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --count='10' --is-file-output-enabled='true']: should generate 10 string(s) on the console and file" {
        $testResult = qlogicae_cli string generate --count='10' --is-file-output-enabled='true' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
        Test-Path $outputFile | Should -BeTrue
    }

    It "[qlogicae_cli string generate --count='10' --is-verbose-logging-enabled='false']: should generate 10 string(s) on the console" {
        $testResult = qlogicae_cli string generate --count='10' --is-verbose-logging-enabled='false' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }

    It "[qlogicae_cli string generate --count='10' --is-verbose-logging-enabled='true'']: should generate 10 string(s) on the console" {
        $testResult = qlogicae_cli string generate --count='10' --is-verbose-logging-enabled='true' | Out-String
        QLogicaePesterTest_ConsoleLog -Text $testResult

        $testResult | Should -Not -BeNullOrEmpty
    }
#>
