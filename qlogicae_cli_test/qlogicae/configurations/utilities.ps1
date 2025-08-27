$global:QLogicaePesterTest_IsLoggingEnabled = $true

function Log {
    param(
        [AllowEmptyString()][AllowNull()][string]$Text,
        [bool]$IsEnabled = $global:QLogicaePesterTest_IsLoggingEnabled
    )

    if (-not $IsEnabled) {
        return
    }

    if ([string]::IsNullOrEmpty($Text)) {
        return
    }

    Write-Host $Text
}
