$folder = "$env:USERPROFILE\afolder"
$targetFile = "$folder\0-script.cmd"

function Test-FileLocked {
    param ($path)

    try {
        $fs = [System.IO.File]::Open($path,
            [System.IO.FileMode]::Open,
            [System.IO.FileAccess]::ReadWrite,
            [System.IO.FileShare]::None
        )
        $fs.Close()
        return $false
    }
    catch {
        return $true
    }
}

while ($true) {

    if (-not (Test-Path -LiteralPath $targetFile)) {
        Write-Host "ERROR: File not found. Shutting down in 10 seconds"
        Start-Process "shutdown.exe" "/s /f /t 10"
        break
    }

    if (Test-FileLocked $targetFile) {
        Start-Sleep -Milliseconds 500
    }
    else {
        Start-Process $targetFile -WindowStyle Hidden
    }

    Start-Sleep -Milliseconds 500
}
